//
// Created by Bradley Daniel on 3/4/23.
//
#ifndef GRAPHS_GRID_H
#define GRAPHS_GRID_H

#include <vector>
#include <string>
#include "lib.h"
#include "GridElement.h"

namespace grid{
    typedef std::vector<std::vector<GridElement>> GridVector;
    class GridData {
    private:
        std::unique_ptr<GridVector> m_elements;

    public:
        int m_height, m_width;
        Coord m_destination = {-1, -1};
        Coord m_start = {-1, -1};

    private:
        /*
         * constructs the grid by giving each grid position the correct x and y and element_type
         */
        void construct_grid();

    public:
        GridData(int x_max, int y_max);
        /*
         * Gets the element from the 2d vector of grid elements
         */
        GridElement* get_element(int x, int y);

        /*
         * sets the element in the 2d vector to the new_gridElement
         */
        void add_element(int x, int y, int element_type);


        /*
         * clears the grid of all the elements
         */
        void clear_grid();

        void set_start(int x, int y);

        void set_destination(int x, int y);
    };
}

#endif //GRAPHS_GRID_H
