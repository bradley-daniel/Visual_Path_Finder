//
// Created by Bradley Daniel on 3/5/23.
//
#include "Graph.h"
#include "GraphNode.h"
#include "Grid.h"
#include "glob.h"

void graph::Graph::construct_graph(Grid::GridData *grid) {
    //insets the first graph position into the vector so the others can fill
    m_vectors.at(0) = {0, 0 , grid->get_element(0, 0)};
    int node_counter = 0;
    for(int i = 0; i < m_max_y; i++) {
        for(int j = 0; j < m_max_x; j++) {
            m_vectors.at(node_counter).add_Node_Edges(this, i, j, grid);
            node_counter++;
        }
    }
}

graph::Graph::Graph(int y_max, int x_max) : m_max_y(y_max), m_max_x(x_max) {
    m_vectors.resize(x_max * y_max);
}

int graph::Graph::get_Vector_Pos(graph::GraphNode *node) const {
    return node->m_coords.flatten_Coord(m_max_x);
}

