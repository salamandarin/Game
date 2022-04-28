// Sam Sutton
#include "move.h"
#include "actor.h"
#include "engine.h"

Move::Move(Vec direction)
    :direction{direction} {
        // error handling
    }


Result Move::perform(Engine& engine) {
    Vec new_position = actor->get_position() + direction;

    Tile& tile = engine.dungeon.tiles(new_position);

    if (tile.is_door()) {
        return failure();
    }

    if (tile.is_wall()) {
        return failure();
    }

    if (tile.actor) {
        return failure();
    }

    else {
        actor->change_direction(direction);
        actor->move_to(new_position);
        return success();
    }
}
