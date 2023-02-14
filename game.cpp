#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

#include <iostream>

#include "classes/direction.h"
#include "classes/pixel.h"
#include "classes/snake.h"
#include "classes/window.h"

int main(void) {
    Window W;
    Snake S{&W};
    char c;

    // clock_t oldTime = clock();
    while (c != 'q') {
        // clock_t now = clock();
        // if (now - oldTime >= 50) {
        // oldTime = now;

        S.draw();

        read(0, &c, 1);
        S.changeDirection(c);
        // }
    }
}