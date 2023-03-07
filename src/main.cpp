#include "Grid.h"
#include "GridWindow.h"
#include "Graph.h"
#include "BreadthFirstSearch.h"
#include "iostream"

#include <ctime>
#include <cstdlib>

int main() {
    srandom(time(nullptr));
    int x_max, y_max;

    gwindow::GridWindow gridwindow = gwindow::GridWindow();
    gridwindow.get_maxyx(y_max, x_max);

    Grid::GridData grid = Grid::GridData(y_max, x_max);

    graph::Graph graph(y_max, x_max);
    graph.construct_graph(&grid);


    gridwindow.display_grid(&grid, &graph);
    return 0;
}


//int main() {
//    srandom(time(nullptr));
//    int x_max = 10, y_max = 5;
//    Grid::GridData grid = Grid::GridData(y_max, x_max);
//    while (1) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        grid.randomize_grid();
//        std::cout << "(" << grid.m_start.m_x << "," << grid.m_start.m_y << ")\n";
//    }
//
//    graph::Graph graph(y_max, x_max);
//    graph.construct_graph(&grid);
//    graph::GraphNode* node = &graph.m_vectors.at(grid.m_start.flatten_coord(grid.m_max_x));
//    auto path_finding = graph::algorithm::BreadthFirstSearch(&graph, node);
//    path_finding.FindPath();
//    return 0;
//}