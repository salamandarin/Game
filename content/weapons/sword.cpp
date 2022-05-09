#include "sword.h"
#include "hit.h"
#include "swing.h"

Sword::Sword(int damage)
    :Weapon{"sword", damage} {}


void Sword::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Hit{defender, damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}