// Sam Sutton
#pragma once

#include "action.h"
#include "dungeon.h"
#include "vec.h"

class Move : public Action {
   public:
    Move(Vec direction);

    Result perform(Engine& engine) override;

   private:
    Vec direction;
};