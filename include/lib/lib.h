//
// Created by Bradley Daniel on 3/5/23.
//

#ifndef GRAPHS_GLIB_H
#define GRAPHS_GLIB_H

namespace lib {
    enum Color_Id {
        Default_color = 1, Start_Color, Destination_Color, FoundDestination_Color, SearchPath_Color, FoundPath_Color, Obstacle_Color
    };

    enum Element_Type {
        Start, Destination, FoundDestination, SearchPath, FoundPath, Obstacle, Empty
    };

    /*
    * gets the color that the node currently should be using based on the element_type
    */
    int get_element_color(int element_type);

    /*
     * gets the char that the element should be using based in the element_type
     */
    char get_element_char(int element_type);

}




#endif //GRAPHS_GLIB_H
