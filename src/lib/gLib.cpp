//
// Created by Bradley Daniel on 3/5/23.
//
#include "gLib.h"

gLib::Coord::Coord(int x, int y) : m_x(x), m_y(y) {}

gLib::Coord::Coord() : m_x(-1), m_y(-1) {}

int gLib::Coord::flatten_coord(int max_x) const {
    int pos = 0;
    pos += m_y*max_x;
    pos += m_x;
    return pos;
}

int gLib::get_element_color(gLib::Element_Type element_type) {
    switch (element_type) {
        case Start:
            return Start_Color;
            break;
        case Destination:
            return Destination_Color;
            break;
        case SearchPath:
            return SearchPath_Color;
            break;
        case FoundPath:
            return FoundPath_Color;
            break;
        case Obstacle:
            return Obstacle_Color;
            break;
        case Empty:
            return Default_color;
            break;
    }
    return Default_color;
}

char gLib::get_element_char(Element_Type element_type) {
    switch (element_type) {
        case gLib::Obstacle:
            return  'O';
            break;
        case gLib::Start:
            return 'S';
            break;
        case gLib::Destination:
            return 'P';
            break;
        case gLib::SearchPath:
            return '.';
            break;
        case gLib::FoundPath:
            return '#';
            break;
        case gLib::Empty:
            return ' ';
            break;
    }
}
