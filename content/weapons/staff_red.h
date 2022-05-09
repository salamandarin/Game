#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"

class StaffRed : public Weapon {
public:
    StaffRed(int damage);

    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};