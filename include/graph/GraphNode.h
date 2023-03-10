//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_GRAPHNODE_H
#define GRAPHS_GRAPHNODE_H

#include "gLib.h"
#include <list>

namespace Grid { class GridElement; class GridData; }

namespace graph {
    class Graph;
    class GraphNode {
    public:
        std::list<GraphNode*> m_adjacency_list;
        Grid::GridElement *m_grid_element = nullptr;
    public:
        GraphNode() = default;
        explicit GraphNode(Grid::GridElement *grid_element);

        /*
         * add the adjacent node adjacency list if the node does not exist in the graph vector add the node information to the vector
         */
        void add_Adjacent_Node(int new_vector_pos, Grid::GridElement *grid_element, Graph *graph);

        /*
         * Links any node in the direction up down left right to the adjacency list by using the current vector position of the node in the graph vector
         */
        void add_Node_Edges(Graph *graph, Grid::GridData *grid);
    };
}


#endif //GRAPHS_GRAPHNODE_H
