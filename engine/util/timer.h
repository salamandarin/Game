#pragma once

#include <chrono>

class Timer {
public:
    Timer();
    double elapsed();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> previous;
};
