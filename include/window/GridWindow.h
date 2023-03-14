//
// Created by Bradley Daniel on 3/4/23.
//
#ifndef GRAPHS_GRIDWINDOW_H
#define GRAPHS_GRIDWINDOW_H

#define COLOR_WALL 100
#define COLOR_SEARCH 101
#define COLOR_FOUND 102
#include "ncurses.h"
#include "glib.h"

namespace grid { class Grid; }
namespace graph { class Graph; }

namespace gwindow {
    class GridWindow {
    public:
    public:
        GridWindow();
        WINDOW *m_grid_window;
    private:
        int m_yMax_scr, m_xMax_scr, m_yBeg_scr, m_xBeg_scr = 0;
        grid::Grid* m_grid;

    private:
        /*
         * Draws the board on the boardWindow
         */

        /*
         * Draws the grid of elements
         */
        void draw_Grid();

        /*
         * Makes each window
         */
        void make_Windows();

        /*
         * define the colors to be used by ncurses
         */
        static void define_Colors();

    public:
        /*
        * Displays the grid for the user
        */
        void display_Grid(graph::Graph* graph);

        void get_terminal_size(int& width, int& height) const;

    };
}


#endif //GRAPHS_GRIDWINDOW_H
