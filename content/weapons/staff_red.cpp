#include "staff_red.h"
#include "hit.h"
#include "swing.h"

StaffRed::StaffRed(int damage)
    :Weapon{"staff_red", damage} {}


void StaffRed::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Hit{defender, damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}