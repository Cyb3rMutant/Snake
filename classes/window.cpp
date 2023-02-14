#include "window.h"

Window::Window() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    cols = ws.ws_col;
    rows = ws.ws_row - 1;
}