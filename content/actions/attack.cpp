#include "attack.h"
#include "engine.h"


Attack::Attack(Actor& attacker, Actor& defender)
    :attacker{attacker}, defender{defender} {}

Result Attack::perform(Engine& engine) {
    attacker.attack(defender);
    return success();
}