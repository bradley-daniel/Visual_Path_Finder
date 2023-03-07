//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_BREADTHFIRSTSEARCH_H
#define GRAPHS_BREADTHFIRSTSEARCH_H

#include "Graph.h"
#include "GraphNode.h"
#include <list>

namespace graph::algorithm {
    struct BreadthFirstSearch {
    public:

    private:
        Graph* m_graph;
        GraphNode* m_start_node;
        std::vector<bool> m_visited;
        std::vector<unsigned> m_distance;
        std::list<GraphNode*> m_node_queue;
        std::vector<GraphNode*> m_predecessor;
    public:
        static void find_Shortest_Path(Graph* graph, GraphNode* start_node, bool& searching_for_path);
    private:
        BreadthFirstSearch(Graph* graph, GraphNode* start_node);
        GraphNode* search_For_Destination();
        GraphNode* visit_Adjacent_Nodes();
    };
}

//namespace graph::algorithm {
//    class BreadthFirstSearch {
//    private:
//        std::list<GraphNode*> node_queue;
//        std::vector<bool> m_visited;
//    private:
//        bool visit_Adjacent_Nodes(Graph* graph, GraphNode* node);
//    public:
//        void run_Search(Graph* graph, GraphNode* start_node);
//
//    };
//}


#endif //GRAPHS_BREADTHFIRSTSEARCH_H
