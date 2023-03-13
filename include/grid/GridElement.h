//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_GRIDELEMENT_H
#define GRAPHS_GRIDELEMENT_H

#include "Coord.h"

namespace grid {
    struct GridElement {
    public:
        char m_element;
        int m_element_type;
        Coord m_coords;
    public:
        GridElement();

        GridElement(int element_type, int x, int y);
        /*
         * updates the element type to a different type
         */
        void update_element(int new_element_type);
    };
}



#endif //GRAPHS_GRIDELEMENT_H
