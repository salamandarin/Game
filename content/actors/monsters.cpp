#include "monsters.h"
#include "none.h"
#include "rest.h"

namespace Monsters {
    constexpr int default_speed{8};

    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
        return std::make_unique<Rest>();
    }

    MonsterType goblin() {
        int health = 2;
        return {"goblin", default_speed, health, std::make_shared<None>(), default_behavior};
    }
}