#ifndef FOOD_H
#define FOOD_H
#include <stdlib.h>
#include <time.h>

#include "pixel.h"

class Food : public Pixel {
public:
    void update(int rows, int cols);
    void draw();
    friend class Snake;
};

#endif