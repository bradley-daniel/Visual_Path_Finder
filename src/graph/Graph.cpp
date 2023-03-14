//
// Created by Bradley Daniel on 3/5/23.
//
#include "Graph.h"
#include "Node.h"
#include "Grid.h"
#include "GridElement.h"
#include "glob.h"

namespace graph {
    void Graph::construct_Graph(grid::Grid *grid) {
        //insets the first graph position into the vector so the others can fill
        m_nodes.at(0) = Node(grid->get_element(0, 0));
        for (auto& vector: m_nodes) {
            add_Node_Edges(&vector);
        }
    }

    Graph::Graph(grid::Grid *grid) : m_grid(grid) {
        m_nodes.resize(grid->m_width * grid->m_height);
    }

    int graph::Graph::get_Vector_Pos(graph::Node *node) const {
        return node->m_grid_element->m_coords.flatten_Coord(m_grid->m_width);

    }

    Node* Graph::add_node(grid::Coord coords,  int vector_pos) {
        Node* node = &m_nodes.at(vector_pos);
        if(node->m_grid_element == nullptr) {
            node->m_grid_element = m_grid->get_element(coords.m_x, coords.m_y);
        }
        return node;
    }

    void Graph::add_Node_Edges(Node* current_node) {
        grid::Coord* current_coord = &current_node->m_grid_element->m_coords;
        //vector location of current node
        int x = current_coord->m_x, y = current_coord->m_y;
        int new_pos, current_pos = current_coord->flatten_Coord(m_grid->m_width);

        //left adjacent check
        if (x > 0) {
            new_pos = current_pos - 1;
            current_node->add_Adjacent_Node(add_node({x-1, y}, new_pos));

        }

        //right adjacent check
        if (x + 1 < m_grid->m_width) {
            new_pos = current_pos + 1;
            current_node->add_Adjacent_Node(add_node({x+1, y}, new_pos));
        }

        //up adjacent check
        if (y > 0) {
            new_pos = current_pos - m_grid->m_width;
            current_node->add_Adjacent_Node(add_node({x, y-1}, new_pos));
        }
        //down adjacent check
        if (y + 1 < m_grid->m_height) {
            new_pos = current_pos + m_grid->m_width;
            current_node->add_Adjacent_Node(add_node({x, y+1}, new_pos));
        }

    }
}
