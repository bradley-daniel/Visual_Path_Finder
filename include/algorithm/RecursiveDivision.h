//
// Created by Bradley Daniel on 3/7/23.
//

#ifndef VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
#define VISUAL_PATH_FINDER_RECURSIVEDIVISION_H

#include "Grid.h"

enum Orientation { Vertical, Horizontal };

class RecursiveDivision {
private:
    Grid::GridData* m_grid;
public:
    static void build_maze(Grid::GridData* grid);
private:
    explicit RecursiveDivision(Grid::GridData* grid);
    void divide(gLib::Coord begin, int height, int width, int orientation, int counter);

    static void draw_Wall(Grid::GridData* grid, gLib::Coord current_wall, int wall_length, int orientation);

    static int get_Quasi_Random_Orientation(int height, int width);
};


#endif //VISUAL_PATH_FINDER_RECURSIVEDIVISION_H
