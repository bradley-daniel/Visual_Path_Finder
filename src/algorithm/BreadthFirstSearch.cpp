//
// Created by Bradley Daniel on 3/6/23.
//
#include "BreadthFirstSearch.h"
#include "GraphNode.h"
#include "Graph.h"
#include "GridElement.h"
#include "gLib.h"
#include <list>
#include <thread>
#include <chrono>

#include <cmath>

namespace graph::algorithm {

    BreadthFirstSearch::BreadthFirstSearch(Graph* graph, GraphNode* start_node) : m_graph(graph), m_start_node(start_node){
        int vector_number = (int)graph->m_vectors.size();
        m_visited.resize(vector_number, false);
        m_distance.resize(vector_number, -1);
        m_predecessor.resize(vector_number, nullptr);
    }

    void BreadthFirstSearch::find_Shortest_Path(Graph *graph, GraphNode *start_node, bool& searching_for_path) {
        BreadthFirstSearch BFS(graph, start_node);
        GraphNode* destination = BFS.search_For_Destination();
        if(destination == nullptr) {
            searching_for_path = false;
            return;
        }

        std::list<GraphNode*> path;
        GraphNode* crawl = destination;
        while(BFS.m_predecessor.at(BFS.m_graph->get_Vector_Pos(crawl)) != nullptr) {
            if(crawl->m_grid_element->m_element_type == gLib::SearchPath) {
                path.emplace_front(crawl);
            }
            crawl = BFS.m_predecessor.at(BFS.m_graph->get_Vector_Pos(crawl));
        }
        destination->m_grid_element->update_element(gLib::FoundDestination);
        for(GraphNode* node : path) {
            node->m_grid_element->update_element(gLib::FoundPath);
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
        searching_for_path = false;
    }

    GraphNode* BreadthFirstSearch::search_For_Destination() {
        m_node_queue.push_back(m_start_node);
        GraphNode* destination_node = nullptr;
        while(!m_node_queue.empty() && destination_node == nullptr) {
            destination_node = visit_Adjacent_Nodes();
            int delay = 750 - std::floor(750 * (m_node_queue.size()/m_graph->m_vectors.size()));
            delay = (delay < 1) ? 1 : delay;
            std::this_thread::sleep_for(std::chrono::microseconds(delay));
        }
        return destination_node;
    }

    GraphNode* BreadthFirstSearch::visit_Adjacent_Nodes() {
        GraphNode* node = m_node_queue.front();
        m_node_queue.pop_front();
        int pos = m_graph->get_Vector_Pos(node);
        m_visited.at(pos) = true;
        for(auto adjacent_node : node->m_adjacency_list) {
            int adj_pos = m_graph->get_Vector_Pos(adjacent_node);
            if(m_visited.at(adj_pos)) continue;
            m_visited.at(adj_pos) = true;
            m_distance.at(adj_pos) = m_distance.at(pos) + 1;
            m_predecessor.at(adj_pos) = node;
            switch(adjacent_node->m_grid_element->m_element_type) {
                case gLib::Empty:
                    adjacent_node->m_grid_element->update_element(gLib::SearchPath);
                    m_node_queue.push_back(adjacent_node);
                    break;
                case gLib::Destination:
                    return adjacent_node;
                default:
                    break;
            }
        }
        return nullptr;
    }
}
