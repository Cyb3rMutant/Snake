#include "snake.h"
extern const RawMode rm;

Snake::Snake(Window* win) : win(win) {
    x = win->cols / 2;
    y = win->rows / 2;

    for (int col = 0; col <= win->cols; col++)
        for (int row = 0; row <= win->rows; row++)
            availableCoordinates.insert(node(col, row));

    food = new Food();
    food->update(win->rows, win->cols);
}

void Snake::fromAvailableToSnake() {
    auto currNode = availableCoordinates.find(node(x, y));
    if (currNode == availableCoordinates.end()) {
        std::cout << "you lose";
        std::exit(0);
    }
    snakeNodes.push_back(*(currNode));
    availableCoordinates.erase(currNode);
}

void Snake::fromSnakeToAvailable() {
    availableCoordinates.insert(snakeNodes.front());
    snakeNodes.pop_front();
}

void Snake::update(int rows, int cols) {
    if (movingDirection == 'x') {
        x += movingDirection;

        if (x < 0)
            x = cols;
        else if (x > cols)
            x = 0;
    } else {
        y += movingDirection;

        if (y < 0)
            y = rows;
        else if (y > rows)
            y = 0;
    }
}

void Snake::draw() {
    fromAvailableToSnake();
    update(win->rows, win->cols);

    printf("\x1b[%d;%dH", (snakeNodes.front()).second + 1,
           (snakeNodes.front()).first + 1);
    printf(" ");
    if (x == food->x && y == food->y) {
        score++;
        food->update(win->rows, win->cols);
    } else {
        fromSnakeToAvailable();
    }

    printf("\x1b[%d;%dH", y + 1, x + 1);
    if (movingDirection == 'x')
        printf("—");
    else
        printf("|");

    printf("\x1b[H\n");
}

void Snake::changeDirection(char keyDirection) {
    if (directions.find(keyDirection) == directions.end())
        return;

    if (directions.at(keyDirection) == movingDirection)
        return;

    movingDirection = directions.at(keyDirection);
}
