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


gwindow::GridWindow::GridWindow() : m_grid_window(nullptr), m_grid(nullptr) {
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
    define_Colors();
    box(stdscr, 0, 0);
    refresh();

}

void gwindow::GridWindow::draw_Grid() {
    int color_id = -1;
    if(m_grid == nullptr) return;
    for(int i = 0; i < getmaxy(m_grid_window); i++) {
        for(int j = 0; j < getmaxx(m_grid_window); j++) {
            const grid::GridElement* element = m_grid->get_element(j, i);
            color_id = glib::get_element_color(element->m_element_type);
            wattron(m_grid_window, COLOR_PAIR(color_id));
            mvwaddch(m_grid_window, i, j, element->m_element);
        }
    }
}

void gwindow::GridWindow::make_Windows() {
    m_grid_window = newwin(m_yMax_scr-2, m_xMax_scr-2, m_yBeg_scr+1, m_xBeg_scr+1);
}

void gwindow::GridWindow::display_Grid(graph::Graph* graph) {
    m_grid = graph->m_grid;
    graph::Node* start_node;
    char input_char = -1;
    std::thread new_thread;
    bool is_algorithm_running = false;
    bool path_found = true;
    do {
        if(new_thread.joinable() && !is_algorithm_running) new_thread.join();
        draw_Grid();
        wrefresh(m_grid_window);
        switch (input_char) {
            case 'r': case 'R':
                if(new_thread.joinable() || !path_found) break;
                is_algorithm_running = true;
                new_thread = std::thread(&algorithm::RecursiveDivision::build_maze, m_grid, std::ref(is_algorithm_running));
                path_found = false;
                break;
            case 'p': case 'P':
                if(new_thread.joinable() || path_found) break;
                is_algorithm_running = true;
                start_node = &graph->m_nodes.at(m_grid->m_start.flatten_Coord(m_grid->m_width));
                new_thread = std::thread(algorithm::BreadthFirstSearch::find_Path, graph, start_node, std::ref(is_algorithm_running));
                path_found = true;
                break;
            default:
                break;
        }
        input_char = getch();
    } while(input_char != 'q' && input_char != 'Q');
    if(new_thread.joinable()) new_thread.join();
    endwin();
}

void gwindow::GridWindow::define_Colors() {
    init_color(COLOR_WALL, 500, 500, 500);
    init_color(COLOR_SEARCH, 0, 650, 750);
    init_color(COLOR_FOUND, 0, 750, 0);

    init_pair(glib::Default_color, COLOR_WHITE, -1);
    init_pair(glib::Start_Color, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(glib::Destination_Color, COLOR_BLACK, COLOR_YELLOW);
    init_pair(glib::FoundDestination_Color, COLOR_BLACK, COLOR_FOUND);
    init_pair(glib::SearchPath_Color, COLOR_SEARCH, -1);
    init_pair(glib::Obstacle_Color, -1, COLOR_WALL);
    init_pair(glib::FoundPath_Color, -1, COLOR_FOUND);
}

void gwindow::GridWindow::get_terminal_size(int& width, int& height) const {
    getmaxyx(m_grid_window, height, width);
}