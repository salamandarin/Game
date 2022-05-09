// Sam Sutton
#include "move.h"
#include "actor.h"
#include "engine.h"
#include "open_door.h"
#include "attack.h"

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
        if (tile.actor->team != actor->team) {
            return alternative(Attack{*actor, *tile.actor});
        }
        return failure();
    }

    else {
        actor->move_to(new_position);
        return success();
    }
}
