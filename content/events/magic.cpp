// Sam Sutton
#include "magic.h"
#include "hit.h"

constexpr int duration = 3;

Magic::Magic(Sprite& sprite, Vec distance, Vec position, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, distance{distance}, position{position},
    defender{defender}, damage{damage},
    delta{distance.x / (duration - 1), distance.y / (duration - 1)} {
        if (distance.x < 0 && distance.y > 0) {
            sprite.angle = 225;
        }
        else if (distance.x == 0 && distance.y > 0) {
            sprite.angle = 270;
        }
        else if (distance.x > 0 && distance.y > 0) {
            sprite.angle = 315;
        }
        else if (distance.x < 0 && distance.y == 0) {
            sprite.angle = 180;
        }
        else if (distance.x > 0 && distance.y == 0) {
            sprite.angle = 0;
        }
        else if (distance.x < 0 && distance.y < 0) {
            sprite.angle = 135;
        }
        else if (distance.x == 0 && distance.y < 0) {
            sprite.angle = 90;
        }
        else {
            sprite.angle = 45;
        }
    }



void Magic::execute(Engine & engine) {
    sprite.shift.x += delta.x;
    sprite.shift.y += delta.y;
}


void Magic::when_done(Engine & engine) {
    engine.events.add(Hit{defender, damage});
}
