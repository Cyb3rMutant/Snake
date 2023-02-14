#include "food.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
// void Food::update(int rows, int cols) {
//     std::srand(time(NULL));
// x = std::rand() % cols;
// y = std::rand() % rows;
//     draw();
// }

void Food::update(int rows, int cols) {
    if (availableCoordinates.empty()) {
        std::cout << "you win";
        std::exit(0);
    }
    std::vector<node> temp;

    std::sample(availableCoordinates.begin(), availableCoordinates.end(),
                std::back_inserter(temp), 1, std::mt19937{std::random_device{}()});

    x = temp[0].first;
    y = temp[0].second;

    draw();
}

void Food::draw() {
    printf("\x1b[%d;%dH", y + 1, x + 1);
    printf("o");
}