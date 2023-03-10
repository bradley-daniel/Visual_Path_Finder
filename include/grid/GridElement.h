//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_GRIDELEMENT_H
#define GRAPHS_GRIDELEMENT_H

#include "gLib.h"

namespace Grid {
    struct GridElement {
    public:
        char m_element;
        gLib::Element_Type m_element_type;
        gLib::Coord m_coords;
    public:
        GridElement();

        GridElement(gLib::Element_Type element_type, int x, int y);

        /*
         * updates the element type to a different type
         */
        void update_element(gLib::Element_Type new_element_type);
    };
}



#endif //GRAPHS_GRIDELEMENT_H
