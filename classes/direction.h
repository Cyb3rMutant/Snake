#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
    char axis;  // store if it's on the X or Y axis
    int dir;    // store if it's going in the + or - side of the axis

    Direction() = delete;  // remove the defualt constructor

   public:
    Direction(char axis, int dir);

    friend bool operator==(const Direction &lhs, const Direction &rhs);

    friend bool operator!=(const Direction &lhs, const Direction &rhs);

    friend bool operator==(const Direction &lhs, const char rhs);

    friend bool operator!=(const Direction &lhs, const char rhs);

    friend int operator+=(int &lhs, const Direction &rhs);
};

#endif