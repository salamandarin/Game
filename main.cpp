#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include "randomness.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::Skelly);
    for (int i = 0; i < 5; ++i) {
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::necromancer());
        // engine.create_monster(Monsters::slime());
        // engine.create_monster(Monsters::demon_big());
        if (probability(5)) {
            engine.create_monster(Monsters::scarlet_witch());
        }
    }
    engine.run();
}
