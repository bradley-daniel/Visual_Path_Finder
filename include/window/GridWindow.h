//
// Created by Bradley Daniel on 3/4/23.
//
#ifndef GRAPHS_GRIDWINDOW_H
#define GRAPHS_GRIDWINDOW_H


#include <utility>
#include "ncurses.h"
#include "gLib.h"
namespace Grid { class GridData; }
namespace graph { class Graph; }


namespace gwindow {
    class GridWindow {
    public:
    public:
        GridWindow();
    private:
        WINDOW *m_boarder_window;
        WINDOW *m_grid_window;
        Grid::GridData *grid_data = nullptr;
        int m_yMax_scr, m_xMax_scr, m_yBeg_scr, m_xBeg_scr = 0;
        Grid::GridData* m_ptr_grid_data;
    private:
        /*
         * Draws the board on the boardWindow
         */
        void draw_Boarder();

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
        void display_Grid(Grid::GridData* grid, graph::Graph* graph);

        void get_Maxyx(int& y_max, int& x_max);
    };
}


#endif //GRAPHS_GRIDWINDOW_H
