// Sam Sutton
#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"

class Witchcraft : public Weapon {
public:
    Witchcraft(int damage);

    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};