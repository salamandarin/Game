#pragma once

#include "vec.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <ostream>


template <typename T>
class Grid {
public:
    Grid()
        :width{0}, height{0} {}
        
    Grid(int width, int height, T initval=T{})
        :width{width}, height{height}, values(width*height, initval) {
        if (width <= 0) {
            std::string msg{"Value width = " + std::to_string(width)};
            msg += " must be greater than 0";
            throw std::runtime_error(msg);
        }
        if (height <= 0) {
            std::string msg{"Value height = " + std::to_string(height)};
            msg += " must be greater than 0";
            throw std::runtime_error(msg);
        }
    }

    const T& operator()(int x, int y) const {
        check_bounds(x, y);
        return values.at(width*y + x);
    }

    const T& operator()(const Vec& vec) const {
        return (*this)(vec.x, vec.y);
    }

    T& operator()(int x, int y) {
        check_bounds(x, y);
        return values.at(width*y + x);
    }

    T& operator()(const Vec& vec) {
        return (*this)(vec.x, vec.y);
    }

    bool within_bounds(int x, int y) const {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    bool within_bounds(const Vec& vec) const {
        return within_bounds(vec.x, vec.y);
    }
    
    void check_bounds(int x, int y) const {
        if (!within_bounds(x, y)) {
            std::string msg{"(" + std::to_string(x) + ", " + std::to_string(y) + ")"};
            msg += " is out of bounds for an array with size ";
            msg += "(" + std::to_string(width) + ", " + std::to_string(height) + ")";
            throw std::runtime_error(msg);
        }
    }

    int width;
    int height;
    
private:
    std::vector<T> values;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Grid<T>& grid) {
    for (int y = 0; y < grid.height; ++y) {
        for (int x = 0; x < grid.width; ++x) {
            os << grid(x, y);
        }
        os << "\n";
    }
    return os;
}

 
