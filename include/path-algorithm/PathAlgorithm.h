//
// Created by Bradley Daniel on 3/14/23.
//

#ifndef VISUAL_PATH_FINDER_PATHALGORITHM_H
#define VISUAL_PATH_FINDER_PATHALGORITHM_H


namespace graph { class Graph; class Node; }

namespace algorithm {
    class PathAlgorithm {
    private:
        graph::Graph* m_graph;
        graph::Node* m_start_node;
    public:
        PathAlgorithm(graph::Graph* graph, graph::Node* start_node);
        static void find_Path(graph::Graph* graph, graph::Node* start_node, bool& searching_for_path);
    };
}

#endif //VISUAL_PATH_FINDER_PATHALGORITHM_H
