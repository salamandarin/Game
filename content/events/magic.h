// Sam Sutton
#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "sprite.h"
#include "vec.h"

class Magic : public Event {
   public:
    Magic(Sprite sprite, Vec distance, Vec position, Actor& defender,
          int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

   private:
    Sprite sprite;
    Vec distance;
    Vec position;
    Vec starting_position;
    Actor& defender;
    int damage;

    Vec delta;
};