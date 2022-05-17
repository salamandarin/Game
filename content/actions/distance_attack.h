// Sam Sutton
#pragma once
#include "action.h"
#include "actor.h"

class DistanceAttack : public Action {
public:
    Result perform(Engine& engine) override;
};