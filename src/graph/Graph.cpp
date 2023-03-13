//
// Created by Bradley Daniel on 3/5/23.
//
#include "Graph.h"
#include "GraphNode.h"
#include "Grid.h"
#include "glob.h"

void graph::Graph::construct_Graph(grid::GridData *grid) {
    //insets the first graph position into the vector so the others can fill
    m_vectors.at(0) = GraphNode(grid->get_element(0, 0));
    for(auto& vector : m_vectors) {
        vector.add_Node_Edges(this,  grid);
    }
}

graph::Graph::Graph(grid::GridData* grid) : m_grid(grid) {
    m_vectors.resize(grid->m_width * grid->m_height);
}

int graph::Graph::get_Vector_Pos(graph::GraphNode *node) const {
    return node->m_grid_element->m_coords.flatten_Coord(m_grid->m_width);
}

