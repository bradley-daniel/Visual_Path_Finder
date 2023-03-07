//
// Created by Bradley Daniel on 3/5/23.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <list>
#include <vector>
#include "gLib.h"
#include "GraphNode.h"

namespace Grid { class GridData; }

namespace graph {
    class Graph {
    public:
        std::vector<GraphNode> m_vectors;
        int m_max_x, m_max_y;
    public:
        Graph(int y_max, int x_max);

        /*
         * constructs an adjacency graph to run path finding algorithm on the data
         */
        void construct_graph(Grid::GridData* grid);

        int get_Vector_Pos(GraphNode* node) const;

    };
}


#endif //GRAPHS_GRAPH_H
