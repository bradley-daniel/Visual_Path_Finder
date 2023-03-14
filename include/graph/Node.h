//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_GRAPHNODE_H
#define GRAPHS_GRAPHNODE_H

#include "lib.h"
#include <list>

namespace grid { class GridElement; class Grid; }

namespace graph {
    class Node {
    public:
        std::list<Node*> m_adjacency_list;
        grid::GridElement *m_grid_element = nullptr;
    public:
        Node() = default;
        explicit Node(grid::GridElement *grid_element);

        /*
         * adds adjacent node to adjacency list
         */
        void add_Adjacent_Node(Node *adjacent_node);
    };
}


#endif //GRAPHS_GRAPHNODE_H
