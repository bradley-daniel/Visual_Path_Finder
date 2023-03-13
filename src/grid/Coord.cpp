//
// Created by Bradley Daniel on 3/13/23.
//
#include "Coord.h"

namespace grid {
    Coord::Coord(int x, int y) : m_x(x), m_y(y) {}

    Coord::Coord() : m_x(-1), m_y(-1) {}

    int Coord::flatten_Coord(int width) const {
        int pos = 0;
        pos += m_y * width;
        pos += m_x;
        return pos;
    }
}
