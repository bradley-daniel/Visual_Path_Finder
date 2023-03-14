//
// Created by Bradley Daniel on 3/14/23.
//

#include "PathAlgorithm.h"

void algorithm::PathAlgorithm::find_Path(graph::Graph *graph, graph::Node *start_node, bool &searching_for_path) {
    searching_for_path = false;
}

algorithm::PathAlgorithm::PathAlgorithm(graph::Graph *graph, graph::Node *start_node) : m_graph(graph), m_start_node(start_node){}
