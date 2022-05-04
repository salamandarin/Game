#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::Skelly);
    engine.create_monster(Monsters::goblin());
    engine.create_monster(Monsters::slime());
    engine.create_monster(Monsters::necromancer());
    engine.run();
}
