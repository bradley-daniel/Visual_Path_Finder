//
// Created by Bradley Daniel on 3/7/23.
//

#include "RecursiveDivision.h"
#include "Grid.h"
#include <lib.h>
#include <thread>
#include <chrono>

using namespace grid;
namespace algorithm {

    RecursiveDivision::RecursiveDivision(grid::Grid *grid) : m_grid(grid) {}

    void RecursiveDivision::build_maze(grid::Grid *grid, bool &is_running) {
        grid->clear_grid();
        RecursiveDivision RD(grid);
        int h = grid->m_height, w = grid->m_width;
        if (w % 2 == 0) {
            draw_Wall(grid, {grid->m_width - 1, 0}, grid->m_height, Vertical);
            w = w - 1;
        }
        if (h % 2 == 0) {
            draw_Wall(grid, {0, grid->m_height - 1}, grid->m_width, Horizontal);
            h = h - 1;
        }
        RD.divide({0, 0}, w, h, choose_Orientation(w, h));
        randomize_Start(grid);
        randomize_Destination(grid);
        is_running = false;
    }


    void RecursiveDivision::randomize_Start(grid::Grid *grid) {
        int x, y;
        do {
            x = 2 * (int) (random() % (grid->m_width / 2));
            y = 2 * (int) (random() % (grid->m_height / 2));
        } while (x == grid->m_destination.m_x && y == grid->m_destination.m_x);
        grid->set_start(x, y);
    }

    void RecursiveDivision::randomize_Destination(grid::Grid *grid) {
        int x, y;
        do {
            x = 2 * (int) (random() % (grid->m_width / 2));
            y = 2 * (int) (random() % (grid->m_height / 2));
        } while (x == grid->m_start.m_x && y == grid->m_start.m_x);
        grid->set_destination(x, y);
    }

    void RecursiveDivision::divide(Coord begin, int width, int height, int isHorizontal) {
        if (width < 2 || height < 2) return;
        Coord wall_begin = randomize_Wall(begin, width, height, isHorizontal);
        int b_x, b_y, h, w;
        w = isHorizontal ? width : (wall_begin.m_x - begin.m_x);
        h = isHorizontal ? (wall_begin.m_y - begin.m_y) : height;
        divide({begin.m_x, begin.m_y}, w, h, choose_Orientation(w, h));

        b_x = isHorizontal ? begin.m_x : (wall_begin.m_x + 1);
        b_y = isHorizontal ? (wall_begin.m_y + 1) : begin.m_y;
        w = isHorizontal ? width : (begin.m_x + width - wall_begin.m_x - 1);
        h = isHorizontal ? (begin.m_y + height - wall_begin.m_y - 1) : height;
        divide({b_x, b_y}, w, h, choose_Orientation(w, h));
    }

    Coord RecursiveDivision::randomize_Wall(Coord begin, int width, int height, int isHorizontal) {
        Coord wall_begin;
        Coord wall_gap;

        int true_height = (height - 1) / 2, true_width = (width - 1) / 2;
        wall_begin.m_x = begin.m_x + (int) (isHorizontal ? 0 : 2 * (random() % (true_width)) + 1);
        wall_begin.m_y = begin.m_y + (int) (isHorizontal ? 2 * (random() % (true_height)) + 1 : 0);

        wall_gap.m_x = wall_begin.m_x + (int) (isHorizontal ? 2 * (random() % true_width) : 0);
        wall_gap.m_y = wall_begin.m_y + (int) (isHorizontal ? 0 : 2 * (random() % true_height));
        draw_Wall(m_grid, wall_begin, isHorizontal ? width : height, isHorizontal);
        m_grid->get_element(wall_gap.m_x, wall_gap.m_y)->update_element(lib::Empty);
        return wall_begin;
    }

    int RecursiveDivision::choose_Orientation(int width, int height) {
        if (height > width) return Horizontal;
        else if (width > height) return Vertical;
        return (int) random() % 2;
    }

    void RecursiveDivision::draw_Wall(grid::Grid *grid, Coord wall_begin, int wall_length, int isHorizontal) {
        int x = wall_begin.m_x, y = wall_begin.m_y;
        for (int i = 0; i < wall_length; i++) {
            std::this_thread::sleep_for(std::chrono::microseconds(500));
            grid->get_element(x, y)->update_element(lib::Obstacle);
            isHorizontal ? x += 1 : y += 1;
        }
    }
}