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
        GraphNode* crawl = destination;
        std::list<GraphNode*> path;
        path.push_back(crawl);
        while(BFS.m_predecessor.at(BFS.m_graph->get_Vector_Pos(crawl)) != nullptr) {
            path.push_back(BFS.m_predecessor.at(BFS.m_graph->get_Vector_Pos(crawl)));
            crawl = BFS.m_predecessor.at(BFS.m_graph->get_Vector_Pos(crawl));
        }
        for(GraphNode* node : path) {
            if(node->m_grid_element->m_element_type == gLib::SearchPath) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                node->m_grid_element->update_element(gLib::FoundPath);
            }
        }
        searching_for_path = false;
    }

    GraphNode* BreadthFirstSearch::search_For_Destination() {
        m_node_queue.push_back(m_start_node);
        GraphNode* destination_node = nullptr;
        while(!m_node_queue.empty() && destination_node == nullptr) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            destination_node = visit_Adjacent_Nodes();
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
