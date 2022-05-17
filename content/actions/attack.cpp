// Sam Sutton
#include "attack.h"
#include "engine.h"

Attack::Attack(Actor& defender)
    :defender{defender} {}

Result Attack::perform(Engine& engine) {
    actor->attack(defender);
    return success();
}