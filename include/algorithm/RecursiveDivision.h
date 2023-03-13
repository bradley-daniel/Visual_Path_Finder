//
// Created by Bradley Daniel on 3/7/23.
//

#ifndef VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
#define VISUAL_PATH_FINDER_RECURSIVEDIVISION_H

#include "Grid.h"
namespace algorithm {
    enum Orientation {
        Vertical, Horizontal
    };

    class RecursiveDivision {
    private:
        grid::GridData *m_grid;
    public:
        static void build_maze(grid::GridData *grid, bool &is_running);

    private:
        explicit RecursiveDivision(grid::GridData *grid);

        void divide(grid::Coord begin, int width, int height, int isHorizontal);

        static void draw_Wall(grid::GridData *grid, grid::Coord wall_begin, int wall_length, int isHorizontal);

        static int choose_Orientation(int width, int height);

        static void randomize_Start(grid::GridData *grid);

        static void randomize_Destination(grid::GridData *grid);

        grid::Coord randomize_Wall(grid::Coord begin, int width, int height, int isHorizontal);
    };
}


#endif //VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
