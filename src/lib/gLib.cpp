//
// Created by Bradley Daniel on 3/5/23.
//
#include "gLib.h"

gLib::Coord::Coord(int x, int y) : m_x(x), m_y(y) {}

gLib::Coord::Coord() : m_x(-1), m_y(-1) {}

int gLib::Coord::flatten_Coord(int width) const {
    int pos = 0;
    pos += m_y * width;
    pos += m_x;
    return pos;
}

int gLib::get_element_color(gLib::Element_Type element_type) {
    switch (element_type) {
        case Start:
            return Start_Color;
        case Destination:
            return Destination_Color;
        case FoundDestination:
            return FoundDestination_Color;
        case SearchPath:
            return SearchPath_Color;
        case FoundPath:
            return FoundPath_Color;
        case Obstacle:
            return Obstacle_Color;
        case Empty:
            return Default_color;
    }
    return Default_color;
}

char gLib::get_element_char(Element_Type element_type) {
    switch (element_type) {
        case Obstacle:
            return ' ';
        case Start:
            return 'S';
        case Destination: case FoundDestination:
            return 'P';
        case SearchPath:
            return '*';
        case gLib::FoundPath:
            return ' ';
        case Empty:
            return ' ';
    }
}
