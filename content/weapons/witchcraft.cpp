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
    Vec distance = defender.get_position() - attacker.get_position();
    Vec position = attacker.get_position();

    if (probability(75)) {
        Sprite red_magic = engine.graphics.get_sprite("red_magic");
        red_magic.location = position;
        // engine.graphics.draw_sprite(position, sprite, 1);
        engine.events.add(Magic{red_magic, distance, position, defender, damage});
    }
    if (probability(20)) {
        engine.events.add(TakeWeapon{defender});
    }
    // else {
    //     engine.events.add(Explode{});
    // }
}