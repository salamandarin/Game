// Sam Sutton
#include "open_door.h"
#include "door.h"
#include "engine.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    Door& door = engine.dungeon.doors.at(position);
    if (!door.is_open()) {
        door.open();

        Tile& tile = engine.dungeon.tiles(position);
        tile.walkable = true;

        engine.events.add(UpdateFOV{});
        return success();
    }
    else {
        actor->move_to(position);
        return success();
    }
}