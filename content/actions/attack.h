#pragma once
#include "action.h"
#include "actor.h"

class Attack : public Action {
public:
    Attack(Actor& attacker, Actor& defender);

    Result perform(Engine& engine) override;
private:
    Actor& attacker;
    Actor& defender;
};