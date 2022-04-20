#include "dungeon.h"
#include "fov.h"
#include "randomness.h"

    
Dungeon::Dungeon(const Grid<Tile>& tiles, const std::vector<Room>& rooms,
                 const std::unordered_map<Vec, Door>& doors,
                 const std::unordered_map<Vec, AnimatedSprite>& doodads)
    :tiles{tiles}, rooms{rooms}, doors{doors}, doodads{doodads} {
    // all tiles are not visible when first created
    for (int y = 0; y < tiles.height; ++y) {
        for (int x = 0; x < tiles.width; ++x) {
            this->tiles(x, y).visible = false;
        }
    }
}


Vec Dungeon::random_open_room_tile() const {
    // strategy: choose a room, then choose a random tile within it if
    // it's walkable and unoccupied
    while (true) {
        auto room = random_choice(rooms);
        int x = randint(room.position.x, room.position.x+room.size.x-1);
        int y = randint(room.position.y, room.position.y+room.size.y-1);
        if (tiles(x, y).walkable && tiles(x, y).actor == nullptr) {
            return {x, y};
        }
    }
}

void Dungeon::update() {
    for (auto& [position, animated_sprite] : doodads) {
        if (tiles(position).visible) {
            animated_sprite.update();
        }
    }
}

void Dungeon::update_visibility(const Vec& position) {
    fog.update_visibility(*this, position);
}

void Dungeon::remove_actor(const Vec& position) {
    tiles(position).actor = nullptr;
}

std::vector<Vec> Dungeon::neighbors(const Vec& position) const {
    std::vector<Vec> neighbors;
    for (const auto& direction : Directions) {
        Vec neighbor = position + direction;
        if (tiles.within_bounds(neighbor)) {
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

bool Dungeon::is_blocking(const Vec& position) const {
    const Tile& tile = tiles(position);
    if (tile.is_wall()) {
        return true;
    }
    else if (tile.is_door()) {
        const Door& door = doors.at(position);
        return !door.is_open(); // closed door
    }
    else {
        return false;
    }
}

std::unordered_set<Vec> Dungeon::calculate_fov(const Vec& position) const {
    FieldOfView fov(*this);
    return fov.compute(position);
}

Path Dungeon::calculate_path(const Vec& start, const Vec& stop) const {
    return breadth_first(*this, start, stop);
}
