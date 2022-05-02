#pragma once
#include "event.h"
#include "actor.h"

class Hit : public Event {
public:
    Hit(Actor& defender, int amount);

    void execute(Engine& engine) override;
    
private:
    Actor& defender;
    int amount;
};