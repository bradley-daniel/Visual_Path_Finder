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
        Grid::GridData* m_grid;
    public:
        explicit Graph(Grid::GridData* grid);
        /*
         * constructs an adjacency graph to run path finding algorithm on the data
         */
        void construct_Graph(Grid::GridData* grid);

        int get_Vector_Pos(GraphNode* node) const;

    };
}


#endif //GRAPHS_GRAPH_H
