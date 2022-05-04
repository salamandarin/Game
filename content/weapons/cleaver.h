#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"

class Cleaver : public Weapon {
public:
    Cleaver(int damage);

    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};