#include "rawMode.h"

RawMode::RawMode() {
    printf("\e[2J");
    std::cout << "\x1b[?25l";  // hide cursor

    tcgetattr(0, &old);
    raw = old;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(0, TCSANOW, &raw);
}

RawMode::~RawMode() {
    tcsetattr(0, TCSANOW, &old);
    std::cout << "\x1b[?25h";  // show curssor
    // printf("\e[2J");
}

const RawMode rm;
