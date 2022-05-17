// Sam Sutton
#pragma once
#include "event.h"
#include "vec.h"
#include "sprite.h"
#include "actor.h"
#include "engine.h"

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& sprite; // original
    Sprite copy;
    Vec direction;
    Actor& defender;
    int damage;

    Vec starting_position;
    double delta; // Change in position
};