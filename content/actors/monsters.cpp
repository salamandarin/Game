#include "monsters.h"
#include "none.h"
#include "rest.h"
#include "wander.h"
#include "randomness.h"
#include "engine.h"
#include "move.h"
#include "staff_red.h"
#include "cleaver.h"
#include "witchcraft.h"
#include "attack.h"

namespace Monsters {
    constexpr int default_speed{8};

    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
        // pursue Hero if monster can see him (If Hero sees me, I see him)
        if (me.is_visible() && engine.hero) {
            Vec from = me.get_position();
            Vec to = engine.hero->get_position();
            std::vector<Vec> path = engine.dungeon.calculate_path(from, to);

            if (path.size() > 1) {
                Vec direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        // Monster doesn't see Hero
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    } 

    std::unique_ptr<Action> witch_behavior(Engine& engine, Monster& me) {
        // pursue Hero if monster can see him (If Hero sees me, I see him)
        if (me.is_visible() && engine.hero) {
            Vec from = me.get_position();
            Vec to = engine.hero->get_position();
            std::vector<Vec> path = engine.dungeon.calculate_path(from, to);


            if (path.size() > 1) {
                if (probability(80)) {
                    return std::make_unique<Attack>(*engine.hero);
                }

                else {
                    Vec direction = path.at(1) - path.at(0);
                    return std::make_unique<Move>(direction);
                }
            }
        }
        // Monster doesn't see Hero
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    }


    MonsterType goblin() {
        int health = 15;
        return {"goblin", default_speed, health, std::make_shared<Cleaver>(5), default_behavior};
    }

    MonsterType slime() {
        int health = 15;
        return {"slime", default_speed, health, std::make_shared<None>(), default_behavior};
    }

    MonsterType necromancer() {
        int health = 20;
        return {"necromancer", default_speed, health, std::make_shared<StaffRed>(10), default_behavior};
    }

    MonsterType demon_big() {
        int health = 40;
        return {"demon_big", default_speed, health, std::make_shared<Cleaver>(20), default_behavior};
    }

    MonsterType scarlet_witch() {
        int health = 100;
        return {"scarlet_witch", default_speed, health, std::make_shared<Witchcraft>(50), witch_behavior};
    }
}