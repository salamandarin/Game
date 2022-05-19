// Sam Sutton
#include "witchcraft.h"
#include "hit.h"
#include "magic.h"
#include "randomness.h"
#include "swing.h"

Witchcraft::Witchcraft(int damage) : Weapon{"none", damage} {}

void Witchcraft::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec distance = defender.get_position() - attacker.get_position();
    Vec position = attacker.get_position();

    Sprite red_magic = engine.graphics.get_sprite("red_magic");
    engine.events.add(Magic{red_magic, distance, position, defender, damage});
}