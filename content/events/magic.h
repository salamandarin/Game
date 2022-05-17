// Sam Sutton
#pragma once
#include "event.h"
#include "vec.h"
#include "sprite.h"
#include "actor.h"
#include "engine.h"

class Magic : public Event {
public:
    Magic(Sprite& sprite, Vec direction, double distance,
          Vec position, Actor& defender, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& sprite;
    Vec direction;
    double distance;
    Vec position;
    Actor& defender;
    int damage;

    double delta;
};