#include "Grid.h"
#include "GridWindow.h"
#include "Graph.h"
#include "BreadthFirstSearch.h"
#include "RecursiveDivision.h"
#include "iostream"

#include <ctime>
#include <cstdlib>

int main() {
    srandom(time(nullptr));
    int x_max, y_max;

    gwindow::GridWindow gridwindow = gwindow::GridWindow();
    gridwindow.get_Maxyx(y_max, x_max);

    Grid::GridData grid = Grid::GridData(y_max, x_max);

    graph::Graph graph(y_max, x_max);
    graph.construct_graph(&grid);


    gridwindow.display_Grid(&grid, &graph);
    return 0;
}

//#include <thread>
//#include <chrono>
//int main() {
//    //wall.m_y = begin.m_y + (int)random() % (height - 2) + 2;
//    //0 1 2 3
//    while(1) {
//        int y = 0;
//        int width = 5;
//        y = y + (int)random() % (width) + 1;
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        std::cout << y << '\n';
//    }
//}

//
//int main() {
//    srandom(time(nullptr));
//    int x_max = 10, y_max = 10;
//    Grid::GridData grid = Grid::GridData(y_max, x_max);
//
//    graph::Graph graph(y_max, x_max);
//    graph.construct_graph(&grid);
//    RecursiveDivision::build_maze(&grid);
//    return 0;
//}