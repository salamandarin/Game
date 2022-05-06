#include "cleaver.h"
#include "hit.h"
#include "swing.h"

Cleaver::Cleaver(int damage)
    :Weapon{"cleaver", damage} {}


void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Hit{defender, damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}