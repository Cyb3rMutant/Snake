#ifndef WINDOW_H
#define WINDOW_H
#include <sys/ioctl.h>
#include <unistd.h>

struct Window {
    int rows;
    int cols;
    Window();
};

#endif