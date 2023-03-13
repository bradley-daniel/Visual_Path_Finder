//
// Created by Bradley Daniel on 3/6/23.
//

#ifndef GRAPHS_BREADTHFIRSTSEARCH_H
#define GRAPHS_BREADTHFIRSTSEARCH_H

#include "Graph.h"
#include "GraphNode.h"
#include <list>

using namespace graph;
namespace algorithm {
    struct BreadthFirstSearch {
    public:

    private:
        Graph* m_graph;
        GraphNode* m_start_node;
        std::vector<bool> m_visited;
        std::vector<unsigned> m_distance;
        std::vector<GraphNode*> m_predecessor;
        std::list<GraphNode*> m_adjacency_queue;
    public:
        /*
         * static method to be called when you want to find the shortest
         */
        static void find_Path(Graph* graph, GraphNode* start_node, bool& searching_for_path);
    private:
        BreadthFirstSearch(Graph* graph, GraphNode* start_node);

        /*
         * Searches the graph for the destination building a distance and predecessor vector from the start to the destination
         * returns the destination if found
         */
        GraphNode* search_For_Destination();
        /*
         * visits the adjacent nodes from the node que and if the node is found return the destination
         */
        GraphNode* visit_Adjacent_Nodes();

        /*
         * constructs a shortest path from the Start -> Destination using the m_distance and m_predecessor
         */
        void construct_Path(GraphNode *destination);

        /*
         * checks if the node is the destination if not update the node to a path
         */
        bool check_Is_Destination(GraphNode *node);
    };
}
#endif //GRAPHS_BREADTHFIRSTSEARCH_H
