# Notes on the Game

Each step for adding a deature:
- Define what you want to do, e.g. *Add a hero*
- Investigating parts of the engine that you need
- Make notes on these parts
- Make a detailed to-do list of what code to write
- Write code
- Add your results to notes (code or screenshot)

## Step 1 - Make my hero show up
Looking in `main.cpp` I see
```C++
#include "engine.h"
#include "heros.h"
engine.create_hero(Heros::nobody);
```
Characters are defined in `content/actors/heros.h`
```C++
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
```

TO DO:
- Look up shared_ptr in Tour of C++ or C++ reference and make_shared: Wht is the relationship? Where do I specify the type?
- Look up undordered_map? string & Reaction
```Reaction = std::function<std::unique_ptr<Action>()>;```, what is a function?
- Go through slides again


## Character stuff
First numbers in txt file are coordinates of top left, next two numbers are dimensions, and last number is how many animation frames (1 is standing still)

## Keybindings

## Actions
- Results are inside action


TO DO 2:
- Add OpenDoor and CloseDoor actions
- Edit Move to return an alternative(OpenDoor)


Speed determines speed of turns
