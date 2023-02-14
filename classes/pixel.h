#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <unordered_set>

#include "hashes.h"

typedef std::pair<int, int> node;

class Pixel {
protected:
    int x;
    int y;

    static std::unordered_set<node, PairHash> availableCoordinates;

public:
    virtual void update(int rows, int cols) = 0;
    virtual void draw() = 0;
};

#endif