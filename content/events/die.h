#pragma once
#include "event.h"
#include "actor.h"

class Die : public Event {
public:
    Die(Actor& actor);
    void execute (Engine& egine) override;

private:
    Actor& actor;
};