//
// Created by Bradley Daniel on 3/14/23.
//
#include "MazeAlgorithm.h"


namespace algorithm {
    void algorithm::MazeAlgorithm::build_maze(grid::Grid* grid, bool& is_running) {
        is_running = false;
    }

    algorithm::MazeAlgorithm::MazeAlgorithm(grid::Grid *grid) : m_grid(grid){}
}