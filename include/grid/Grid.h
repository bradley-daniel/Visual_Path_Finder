//
// Created by Bradley Daniel on 3/4/23.
//
#ifndef GRAPHS_GRID_H
#define GRAPHS_GRID_H

#include <vector>
#include <string>
#include "gLib.h"
#include "GridElement.h"

namespace Grid{
    typedef std::vector<std::vector<GridElement>> GridVector;
    class GridData {
    private:
        std::unique_ptr<GridVector> m_elements;

    public:
        int m_height, m_width;
        gLib::Coord m_destination = {-1, -1};
        gLib::Coord m_start = {-1, -1};

    private:
        /*
         * constructs the grid by giving each grid position the correct x and y and element_type
         */
        void construct_grid();

    public:
        GridData(int y_max, int x_max);
        /*
         * Gets the element from the 2d vector of grid elements
         */
        GridElement* get_element(int y, int x);

        /*
         * sets the element in the 2d vector to the new_gridElement
         */
        void add_element(int y, int x, gLib::Element_Type element_type);

        /*
         * Randomize the grid of elements
         */
        void randomize_grid();

        /*
         * Randomizes the place were the "Player" starts
         */
        void randomize_start();

        /*
         * Randomizes the destination
         */
        void randomize_destination();

        /*
         * clears the grid of all the elements
         */
        void clear_grid();

    };
}

#endif //GRAPHS_GRID_H
