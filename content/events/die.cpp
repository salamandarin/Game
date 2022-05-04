#include "die.h"
#include "engine.h"

Die::Die(Actor& actor)
    :actor{actor} {}


void Die::execute(Engine& engine) {
    // Remove actor from its tile
    engine.dungeon.remove_actor(actor.get_position());

    // Remove it from live actors
    actor.health = 0;
    actor.alive = false;
}