//
// Created by Bradley Daniel on 3/7/23.
//

#include "RecursiveDivision.h"
#include "Grid.h"
#include "GridElement.h"
#include <thread>
#include <gLib.h>
#include <chrono>

RecursiveDivision::RecursiveDivision(Grid::GridData *grid) : m_grid(grid) {}

void RecursiveDivision::build_maze(Grid::GridData* grid) {
    RecursiveDivision RD(grid);
    int w = grid->m_width, h = grid->m_height;
    if(w%2) {
        draw_Wall(grid, {0, h-1}, w, Horizontal);
    }
    if(h%2) {
        draw_Wall(grid, {w-1, 0}, h, Vertical);
    }
//    RD.divide({0, 0}, grid->m_height, grid->m_width, get_Quasi_Random_Orientation(grid->m_height, grid->m_width), 0);
}

void RecursiveDivision::divide(gLib::Coord begin, int height, int width, int orientation, int counter) {

}

int RecursiveDivision::get_Quasi_Random_Orientation(int height, int width) {
    if(height > width) return Horizontal;
    else if(width > height) return Vertical;
    return (int)random() % 2;
}

void RecursiveDivision::draw_Wall(Grid::GridData* grid, gLib::Coord current_wall, int wall_length, int orientation) {
    int x = current_wall.m_x, y = current_wall.m_y;
    for (int i = 0; i < wall_length; i++) {
        grid->get_element(y, x)->update_element(gLib::Obstacle);
        if (orientation == Horizontal) {
            x += 1;
        } else {
            y += 1;
        }
    }
}
