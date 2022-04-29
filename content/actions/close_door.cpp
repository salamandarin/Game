#include "close_door.h"
#include "engine.h"
#include "actor.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine) {
    bool closed_any_doors{false};
    auto neighbors = engine.dungeon.neighbors(actor->get_position());
    for (const Vec&position : neighbors) {
        Tile&tile = engine.dungeon.tiles(position);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(position);
            if (door.is_open()) {
                door.close();
                tile.walkable = false;
                closed_any_doors = true;
            }
        }
    }
    if (closed_any_doors) {
        engine.events.add(UpdateFOV{});
        return success();
    }

    else {
        return failure();
    }
}
