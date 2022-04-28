#pragma once
#include "action.h"

class CloseDoor : public Action {
public:
    CloseDoor();

    Result perform(Engine& engine) override;
};