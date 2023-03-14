#include "Grid.h"
#include "GridWindow.h"
#include "Graph.h"
#include <iostream>

int main() {
    srandom(time(nullptr));
    int x_max = 0, y_max = 0;
    gwindow::GridWindow gridwindow = gwindow::GridWindow();
    gridwindow.get_Maxyx(y_max, x_max);
    grid::Grid grid = grid::Grid(x_max, y_max);
    graph::Graph graph(&grid);
    graph.construct_Graph(&grid);
    gridwindow.display_Grid(&graph);
    return 0;
}