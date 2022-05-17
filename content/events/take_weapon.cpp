// Sam Sutton
#include "take_weapon.h"
#include "hit.h"

constexpr int duration = 3;

TakeWeapon::TakeWeapon(Actor& defender)
    :Event{duration}, defender{defender}, damage{100} {}


void TakeWeapon::execute(Engine & engine) {
    // Remove defender's weapon
}


void TakeWeapon::when_done(Engine & engine) {
    engine.events.add(Hit{defender, damage});
}
