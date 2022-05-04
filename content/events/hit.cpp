#include "hit.h"
#include "engine.h"
#include "die.h"

Hit::Hit(Actor& defender, int amount)
    :defender{defender}, amount{amount} {}


void Hit::execute(Engine& engine) {
    defender.take_damage(amount);
    // events.add(flashing red cirlcle)
    if (defender.health <= 0) {
        engine.events.add(Die{defender});
    }
}
