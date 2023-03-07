//
// Created by Bradley Daniel on 3/5/23.
//

#ifndef GRAPHS_GLIB_H
#define GRAPHS_GLIB_H

namespace gLib {
    struct Coord {
    public:
        int m_x, m_y;
        Coord(int x, int y);
    public:
        [[nodiscard]] int flatten_coord(int max_x) const;
        Coord();
    };

    enum Color_Id {
        Default_color = 1, Start_Color, Destination_Color, SearchPath_Color, FoundPath_Color, Obstacle_Color
    };

    enum Element_Type {
        Start, Destination, SearchPath, FoundPath, Obstacle, Empty
    };

    /*
    * gets the color that the node currently should be using based on the element_type
    */
    int get_element_color(gLib::Element_Type element_type);

    /*
     * gets the char that the element should be using based in the element_type
     */
    char get_element_char(Element_Type element_type);

}




#endif //GRAPHS_GLIB_H
