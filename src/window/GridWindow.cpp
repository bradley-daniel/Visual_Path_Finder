//
// Created by Bradley Daniel on 3/4/23.
//
#include "GridWindow.h"
#include "Grid.h"
#include "Graph.h"
#include "BreadthFirstSearch.h"
#include "RecursiveDivision.h"
#include "GridElement.h"
#include <iostream>
#include <thread>


gwindow::GridWindow::GridWindow() : m_boarder_window(nullptr), m_grid_window(nullptr), m_ptr_grid_data(nullptr) {
    initscr();
    start_color();
    use_default_colors();
    noecho();
    curs_set(FALSE);
    refresh();
    timeout(25);
    getmaxyx(stdscr, m_yMax_scr, m_xMax_scr);
    getbegyx(stdscr, m_yBeg_scr, m_xBeg_scr);
    make_Windows();
    draw_Boarder();
    define_Colors();
}

void gwindow::GridWindow::draw_Boarder() {
    box(m_boarder_window, 0, 0);
}



void gwindow::GridWindow::draw_Grid() {

    int color_id = -1;
    if(m_ptr_grid_data == nullptr) return;
    for(int i = 0; i < getmaxy(m_grid_window); i++) {
        for(int j = 0; j < getmaxx(m_grid_window); j++) {
            const Grid::GridElement* element = m_ptr_grid_data->get_element(i, j);
            color_id = gLib::get_element_color(element->m_element_type);
            wattron(m_grid_window, COLOR_PAIR(color_id));
            mvwaddch(m_grid_window, i, j, element->m_element);
            wattroff(m_grid_window, COLOR_PAIR(color_id));
        }
    }
//    wprintw()
}

void gwindow::GridWindow::make_Windows() {
    m_boarder_window = newwin(m_yMax_scr, m_xMax_scr, m_yBeg_scr, m_xBeg_scr);
    m_grid_window = newwin(m_yMax_scr-2, m_xMax_scr-2, m_yBeg_scr+1, m_xBeg_scr+1);
}

void gwindow::GridWindow::display_Grid(Grid::GridData* grid, graph::Graph* graph) {
    wrefresh(m_boarder_window);
    m_ptr_grid_data = grid;
    graph::GraphNode* start_node;
    char input_char = -1;
    std::thread new_thread;
    bool is_algorithm_running = false;
    do {
        draw_Grid();
        wrefresh(m_grid_window);


        switch (input_char) {
            case 'r': case 'R':
                if(is_algorithm_running) break;
                is_algorithm_running = true;
                new_thread = std::thread(&RecursiveDivision::build_maze, grid, std::ref(is_algorithm_running));
//                grid->randomize_grid();
                break;
            case 'p': case 'P':
                if(is_algorithm_running) break;
                is_algorithm_running = true;
                start_node = &graph->m_vectors.at(grid->m_start.flatten_Coord(graph->m_max_x));
                new_thread = std::thread(graph::algorithm::BreadthFirstSearch::find_Shortest_Path, graph, start_node, std::ref(is_algorithm_running));
                break;
            default:
                break;
        }
//        doupdate();
        if(new_thread.joinable() && !is_algorithm_running) new_thread.join();
        input_char = getch();
    } while(input_char != 'q' && input_char != 'Q');
    if(new_thread.joinable()) new_thread.join();
    endwin();
}

#define COLOR_WALL 100
#define COLOR_SEARCH 101
#define COLOR_FOUND 102

void gwindow::GridWindow::define_Colors() {
    init_color(COLOR_WALL, 550, 550, 550);
    init_color(COLOR_SEARCH, 0, 500, 700);
    init_color(COLOR_FOUND, 0, 1000, 0);


    init_pair(gLib::Default_color, COLOR_WHITE, -1);
    init_pair(gLib::Start_Color, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(gLib::Destination_Color, COLOR_BLACK, COLOR_YELLOW);
    init_pair(gLib::FoundDestination_Color, COLOR_BLACK, COLOR_GREEN);
    init_pair(gLib::FoundPath_Color, COLOR_GREEN, -1);

    init_pair(gLib::SearchPath_Color, COLOR_SEARCH, -1);

//    init_pair(gLib::Obstacle_Color, COLOR_RED, -1);
    init_pair(gLib::Obstacle_Color, COLOR_WALL, COLOR_WALL);

    init_pair(gLib::FoundPath_Color, COLOR_BLACK, COLOR_GREEN);







//    init_pair(gLib::Obstacle_Color, -1, COLOR_RED);
}

void gwindow::GridWindow::get_Maxyx(int& y_max, int& x_max) {
    getmaxyx(m_grid_window, y_max, x_max);
}