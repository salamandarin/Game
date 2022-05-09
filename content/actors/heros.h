#pragma once

#include "herotype.h"
#include "none.h"
#include "move.h"
#include "rest.h"
#include "close_door.h"
#include "cleaver.h"
#include "sword.h"
#include "staff_green.h"

namespace Heros {
    using Reaction = std::function<std::unique_ptr<Action>()>;

    std::unordered_map<std::string, Reaction> key_bindings = {
    {"Left", []() { return std::make_unique<Move>(Vec{-1, 0}); }},
    {"Right", []() { return std::make_unique<Move>(Vec{1, 0}); }},
    {"Up", []() { return std::make_unique<Move>(Vec{0, 1}); }},
    {"Down", []() { return std::make_unique<Move>(Vec{0, -1}); }},

    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},
    };
    
    
    constexpr int default_speed{8};
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), key_bindings};
    const HeroType Skelly{"skeleton", default_speed, 1, std::make_shared<Sword>(20), key_bindings};
}
