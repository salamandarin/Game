#include "staff_green.h"
#include "hit.h"
#include "swing.h"

StaffGreen::StaffGreen(int damage)
    :Weapon{"staff_green", damage} {}


void StaffGreen::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}