// Sam Sutton
#include "witchcraft.h"
#include "hit.h"
#include "swing.h"
#include "randomness.h"
#include "magic.h"
#include "take_weapon.h"

Witchcraft::Witchcraft(int damage)
    :Weapon{"none", damage} {}


void Witchcraft::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::vector<Vec> path = engine.dungeon.calculate_path(attacker.get_position(), defender.get_position());
    double distance = path.size();
    Vec position = attacker.get_position();

    if (probability(75)) {
        Sprite red_magic = engine.graphics.get_sprite("red_magic");
        engine.events.add(Magic{red_magic, direction, distance, position, defender, damage});
    }
    if (probability(20)) {
        engine.events.add(TakeWeapon{defender});
    }
    // else {
    //     engine.events.add(Explode{});
    // }
}