#include "direction.h"

#include <unordered_map>

Direction::Direction(char axis, int dir) : axis(axis), dir(dir) {}

bool operator==(const Direction &lhs, const Direction &rhs) {
    return lhs.axis == rhs.axis;
}

bool operator!=(const Direction &lhs, const Direction &rhs) {
    return lhs.axis != rhs.axis;
}

bool operator==(const Direction &lhs, const char rhs) {
    return lhs.axis == rhs;
}

bool operator!=(const Direction &lhs, const char rhs) {
    return lhs.axis != rhs;
}

int operator+=(int &lhs, const Direction &rhs) {
    return (lhs = lhs + rhs.dir);
}