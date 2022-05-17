#pragma once
#include "action.h"
#include "monster.h"
#include <memory>

namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);
    std::unique_ptr<Action> witch_behavior(Engine& engine, Monster& me);


    MonsterType goblin();
    MonsterType slime();
    MonsterType necromancer();
    MonsterType demon_big();
    MonsterType scarlet_witch();
}
