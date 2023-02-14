#ifndef HASHES_H
#define HASHES_H
#include <iostream>

struct PairHash {
    std::size_t operator()(const std::pair<int, int>& v) const;
};
#endif