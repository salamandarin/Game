// Sam Sutton
#include "distance_attack.h"
#include "engine.h"

Result DistanceAttack::perform(Engine& engine) {
    // Check if actor has distance weapon first??
    auto neighbors = engine.dungeon.neighbors(actor->get_position());
    for (const Vec&position : neighbors) {
        Tile&tile = engine.dungeon.tiles(position);
        if (tile.actor) {
            if (tile.actor->team != actor->team) {
                Actor& defender = *tile.actor;
                actor->attack(defender);
                return success();
            }
        }
        auto neighbors2 = engine.dungeon.neighbors(position);
        for (const Vec&position2 : neighbors2) {
            Tile&tile = engine.dungeon.tiles(position2);
            if (tile.actor) {
                if (tile.actor->team != actor->team) {
                    Actor& defender = *tile.actor;
                    actor->attack(defender);
                    return success();
                }
            }
            auto neighbors3 = engine.dungeon.neighbors(position2);
            for (const Vec&position3 : neighbors3) {
                Tile&tile = engine.dungeon.tiles(position3);
                if (tile.actor) {
                    if (tile.actor->team != actor->team) {
                        Actor& defender = *tile.actor;
                        actor->attack(defender);
                        return success();
                    }
                }
                auto neighbors4 = engine.dungeon.neighbors(position3);
                for (const Vec&position4 : neighbors4) {
                    Tile&tile = engine.dungeon.tiles(position4);
                    if (tile.actor) {
                        if (tile.actor->team != actor->team) {
                            Actor& defender = *tile.actor;
                            actor->attack(defender);
                            return success();
                        }
                    }
                }
            }
        }
    }
    return failure();
}