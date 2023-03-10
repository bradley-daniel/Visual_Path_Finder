#include "Grid.h"
#include "GridWindow.h"
#include "Graph.h"
#include <iostream>


struct test {
    std::list<int*> test_1;
    int* t;
};

int main() {
    srandom(time(nullptr));
    int x_max = 15, y_max = 10;

    gwindow::GridWindow gridwindow = gwindow::GridWindow();
    gridwindow.get_Maxyx(y_max, x_max);

    Grid::GridData grid = Grid::GridData(x_max, y_max);
    graph::Graph graph(&grid);
    graph.construct_Graph(&grid);
    gridwindow.display_Grid(&graph);
    return 0;
}