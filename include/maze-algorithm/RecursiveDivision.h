//
// Created by Bradley Daniel on 3/7/23.
//

#ifndef VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
#define VISUAL_PATH_FINDER_RECURSIVEDIVISION_H

#include "Grid.h"
#include "MazeAlgorithm.h"

namespace algorithm {
    enum Orientation {
        Vertical, Horizontal
    };

    class RecursiveDivision : public MazeAlgorithm {
    public:
        /*
         * Build maze using Recursive Division
         */
        static void build_maze(grid::Grid *grid, bool &is_running);

    private:
        explicit RecursiveDivision(grid::Grid *grid);

        /*
         * Recursive method to define the new left width/height and right width/height
         */
        void divide(grid::Coord begin, int width, int height, int isHorizontal);

        /*
         * Draw wall from the wall_begins that is the length of wall_length
         */
        void draw_Wall(grid::Coord wall_begin, int wall_length, int isHorizontal);

        /*
         * Choose a orientation if width > height Horizontal else if height > width Vertical else random
         */
        static int choose_Orientation(int width, int height);

        /*
         * randomize the start in the grid
         */
        static void randomize_Start(grid::Grid *grid);

        /*
         * randomize the destination in the grid
         */
        static void randomize_Destination(grid::Grid *grid);

        /*
         * randomize the wall location of the wall
         */
        grid::Coord randomize_Wall(grid::Coord begin, int width, int height, int isHorizontal);
    };
}

#endif //VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
