//
// Created by Bradley Daniel on 3/6/23.
//
#include "GraphNode.h"
#include "Graph.h"
#include "Grid.h"
#include "GridElement.h"

graph::GraphNode::GraphNode(int y, int x, Grid::GridElement* gridElement) : m_coords({x, y}), m_grid_element(gridElement) {}

void graph::GraphNode::add_Adjacent_Node(int new_vector_pos, Grid::GridElement* grid_element, graph::Graph *graph) {
    if(graph->m_vectors.at(new_vector_pos).m_grid_element == nullptr) {
        graph->m_vectors.at(new_vector_pos) = {grid_element->m_coords.m_y, grid_element->m_coords.m_x, grid_element };
    }
    m_adjacency_list.emplace_back(&graph->m_vectors.at(new_vector_pos));
}


void graph::GraphNode::add_Node_Edges(graph::Graph* graph, int y, int x, Grid::GridData* grid) {
    //vector location of current node
    int v_node_pos = m_coords.flatten_Coord(grid->m_width);

    //vector position of the coordinate values
    int v_left_pos = v_node_pos-1;
    int v_right_pos = v_node_pos+1;
    int v_up_pos = v_node_pos-grid->m_width;
    int v_down_pos = v_node_pos+grid->m_width;

    //left adjacent check
    if(m_coords.m_x > 0) {
        add_Adjacent_Node(v_left_pos, grid->get_element(y, x-1) , graph);
    }
    //right adjacent check
    if(m_coords.m_x + 1 < grid->m_width){
        add_Adjacent_Node(v_right_pos, grid->get_element(y, x+1), graph);
    }

    //up adjacent check
    if(m_coords.m_y > 0) {
        add_Adjacent_Node(v_up_pos, grid->get_element(y - 1, x), graph);
    }
    //down adjacent check
    if(m_coords.m_y + 1 < grid->m_height) {
        add_Adjacent_Node(v_down_pos, grid->get_element(y + 1, x), graph);
    }

}