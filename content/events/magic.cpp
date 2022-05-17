// Sam Sutton
#include "magic.h"
#include "hit.h"

constexpr int duration = 3;

Magic::Magic(Sprite& sprite, Vec direction, double distance,
             Vec position, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, direction{direction},
    distance{distance}, position{position}, defender{defender},
    damage{damage}, delta{distance / (duration - 1)} {
        if (direction == Vec{1, 0}) {
            sprite.angle = 0;
        }
        else if (direction == Vec{-1, 0}) {
            sprite.angle = 180;
            delta *= -1;
        }
        else if (direction == Vec{0, 1}) {
            sprite.shift.y -= 12;
            sprite.angle = 270;
        }
        else {
            sprite.shift.x = 0;
            sprite.angle = 90;
            delta *= -1;
        }
    }



void Magic::execute(Engine & engine) {
    if (direction == Vec{1, 0} || direction == Vec{-1, 0}) {
        sprite.shift.x += position.x + delta * frame_count;
    }
    else {
        sprite.shift.y += position.y + delta * frame_count;
    }
    engine.graphics.draw_sprite(position, sprite, 1);

}


void Magic::when_done(Engine & engine) {
    engine.events.add(Hit{defender, damage});
}
