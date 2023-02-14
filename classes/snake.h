#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include <unordered_map>

#include "direction.h"
#include "food.h"
#include "pixel.h"
#include "rawMode.h"
#include "window.h"

const std::unordered_map<char, Direction> directions = {{'w', *(new Direction('y', -1))},
                                                        {'a', *(new Direction('x', -1))},
                                                        {'s', *(new Direction('y', 1))},
                                                        {'d', *(new Direction('x', 1))}};

class Snake : public Pixel {
    int score = 0;
    bool eaten = false;

    std::deque<node> snakeNodes;

    Direction movingDirection = directions.at('a');
    Window *win;
    Food *food;

    Snake() = delete;

    void fromAvailableToSnake();
    void fromSnakeToAvailable();

public:
    Snake(Window *win);

    void update(int rows, int cols);

    void draw();

    void changeDirection(char keyDirection);
};

#endif