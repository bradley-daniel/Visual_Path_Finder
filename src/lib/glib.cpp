//
// Created by Bradley Daniel on 3/5/23.
//
#include "glib.h"

int glib::get_element_color(int element_type) {
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

char glib::get_element_char(int element_type) {
    switch (element_type) {
        case Obstacle:
            return ' ';
        case Start:
            return 'S';
        case Destination: case FoundDestination:
            return 'P';
        case SearchPath:
            return '*';
        case glib::FoundPath:
            return ' ';
        case Empty:
            return ' ';
    }
    return ' ';
}
