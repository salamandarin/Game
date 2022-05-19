// Sam Sutton
#include "magic.h"
#include "hit.h"
#include <cmath>

constexpr int duration = 2;

Magic::Magic(Sprite sprite, Vec distance, Vec position, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, distance{distance}, position{position},
    starting_position{position}, defender{defender}, damage{damage},
    delta{distance.x / (duration - 1), distance.y / (duration - 1)} {}


void Magic::execute(Engine& engine) {
    sprite.angle = (atan2(distance.x, distance.y) * 180 / M_PI) - 90;

    position.x = starting_position.x + delta.x * frame_count;
    position.y = starting_position.y + delta.y * frame_count;

    engine.camera.add_overlay(position, sprite);
}

void Magic::when_done(Engine& engine) {
    engine.events.add(Hit{defender, damage});
}
