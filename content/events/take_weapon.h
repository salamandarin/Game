// Sam Sutton
#pragma once
#include "event.h"
#include "vec.h"
#include "sprite.h"
#include "actor.h"
#include "engine.h"

class TakeWeapon : public Event {
public:
    TakeWeapon(Actor& defender);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite sprite;
    Actor& defender;
    int damage;
};