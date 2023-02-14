#ifndef RAWMODE_H
#define RAWMODE_H
#include <termios.h>

#include <iostream>

class RawMode {
    struct termios old, raw;

   public:
    RawMode();

    ~RawMode();
};

#endif