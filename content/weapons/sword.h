#pragma once
#include "weapon.h"
#include "engine.h"
#include "actor.h"

class Sword : public Weapon {
public:
    Sword(int damage);

    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};