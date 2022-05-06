#include "swing.h"
#include "hit.h"

constexpr int duration = 3;

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, copy{sprite}, direction{direction},
    defender{defender}, damage{damage}, starting_angle{sprite.angle} {
        if (direction == Vec{1, 0}) {
            starting_angle = 0;
            delta = 135.0 / (duration -1);
        }
    }


void Swing::execute(Engine& engine) {
    // Modify the sprite
    sprite.angle += starting_angle + delta * frame_count;
}

void Swing::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}

