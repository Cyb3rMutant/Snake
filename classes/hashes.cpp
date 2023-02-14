#include "hashes.h"

std::size_t PairHash::operator()(const std::pair<int, int>& v) const {
    return v.first * 31 + v.second;
}