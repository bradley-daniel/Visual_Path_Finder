//
// Created by Bradley Daniel on 3/6/23.
//
#include "Node.h"
#include "Graph.h"
#include "Grid.h"
#include "GridElement.h"

graph::Node::Node(grid::GridElement* grid_element) : m_grid_element(grid_element) {}

void graph::Node::add_Adjacent_Node(Node* adjacent_node) {
    m_adjacency_list.emplace_back(adjacent_node);
}