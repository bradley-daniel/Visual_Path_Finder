//
// Created by Bradley Daniel on 3/5/23.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <list>
#include <vector>
#include "lib.h"
#include "GraphNode.h"

namespace grid { class GridData; }

namespace graph {
    class Graph {
    public:
        std::vector<GraphNode> m_vectors;
        grid::GridData* m_grid;
    public:
        explicit Graph(grid::GridData* grid);
        /*
         * constructs an adjacency graph to run path finding algorithm on the data
         */
        void construct_Graph(grid::GridData* grid);

        int get_Vector_Pos(GraphNode* node) const;

    };
}


#endif //GRAPHS_GRAPH_H
