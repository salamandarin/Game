#pragma once
#include "event.h"
#include "vec.h"
#include "sprite.h"
#include "actor.h"
#include "engine.h"

class Swing : public Event {
public:
    Swing(Sprite& sprite, Vec direction, Actor& defender, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& sprite; // original
    Sprite copy;
    Vec direction;
    Actor& defender;
    int damage;

    double starting_angle;
    double delta; // Change in angle
    
};