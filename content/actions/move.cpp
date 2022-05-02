// Sam Sutton
#include "move.h"
#include "actor.h"
#include "engine.h"
#include "open_door.h"

Move::Move(Vec direction)
    :direction{direction} {}


Result Move::perform(Engine& engine) {
    Vec new_position = actor->get_position() + direction;
    
    actor->change_direction(direction);

    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_door() && !tile.walkable) {
        return alternative(OpenDoor{new_position});
    }

    if (tile.is_wall()) {
        return failure();
    }

    if (tile.actor) {
        return failure(); // alternative(Attack{*tile.actor})
        //                                     Actor& actor
    }

    else {
        actor->move_to(new_position);
        return success();
    }
}
