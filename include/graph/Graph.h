//
// Created by Bradley Daniel on 3/5/23.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <list>
#include <vector>
#include "lib.h"
#include "Node.h"

namespace grid { class Grid; class Coord; }
namespace graph {
    class Graph {
    public:
        std::vector<Node> m_nodes;
        grid::Grid* m_grid;
    private:
        /*
         * adds vector to the vector of nodes
         */
        Node* add_node(grid::Coord coords,  int vector_pos);

        /*s
         * checks the cardinal directions for potential edges and adds them using add_node
         */
        void add_Node_Edges(Node* current_node);

    public:
        explicit Graph(grid::Grid* grid);
        /*
         * constructs an adjacency graph to run path finding algorithm on the data
         */
        void construct_Graph(grid::Grid* grid);

        /*
         * return the position of a node within the vector that stores the grid element
         */
        int get_Vector_Pos(Node* node) const;
    };
}




#endif //GRAPHS_GRAPH_H
