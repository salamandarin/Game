// Sam Sutton
#include "thrust.h"
#include "hit.h"

constexpr int duration = 3;

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, copy{sprite}, direction{direction},
    defender{defender}, damage{damage}, starting_position{sprite.location},
    delta{5 / (duration -1)} {
        if (direction == Vec{1, 0}) {
            sprite.angle = 90;
        }
        else if (direction == Vec{-1, 0}) {
            sprite.angle = 270;
            delta *= -1;
        }
        else if (direction == Vec{0, 1}) {
            sprite.shift.y -= 16;
            sprite.angle = 0;    
        }
        else {
            sprite.shift.y -= 12;
            sprite.angle = 180;
            delta *= -1;
        }
    }


void Thrust::execute(Engine& engine) {
    if (direction == Vec{1, 0} || direction == Vec{-1, 0}) {
        sprite.shift.x += delta;
    }
    else {
        sprite.shift.y += delta;
    }
}

void Thrust::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}