// Sam Sutton
#include "witchcraft.h"
#include "hit.h"
#include "swing.h"

Witchcraft::Witchcraft(int damage)
    :Weapon{"none", damage} {}


void Witchcraft::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}