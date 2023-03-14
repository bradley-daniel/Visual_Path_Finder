//
// Created by Bradley Daniel on 3/6/23.
//
#include "BreadthFirstSearch.h"
#include "Node.h"
#include "Graph.h"
#include "GridElement.h"
#include "glib.h"
#include <list>
#include <thread>
#include <chrono>

namespace algorithm {
    BreadthFirstSearch::BreadthFirstSearch(Graph* graph, Node* start_node) : PathAlgorithm(graph, start_node) {
        int vector_number = (int)graph->m_nodes.size();
        m_visited.resize(vector_number, false);
        m_distance.resize(vector_number, -1);
        m_predecessor.resize(vector_number, nullptr);
    }

    void BreadthFirstSearch::find_Path(Graph *graph, Node *start_node, bool& searching_for_path) {
        BreadthFirstSearch BFS(graph, start_node);
        Node* destination = BFS.search_For_Destination();
        BFS.construct_Path(destination);
        searching_for_path = false;
    }

    void BreadthFirstSearch::construct_Path(Node* destination) {
        if(destination == nullptr) return;
        std::list<Node*> path;
        Node* crawl = destination;
        while(m_predecessor.at(m_graph->get_Vector_Pos(crawl)) != nullptr) {
            if(crawl->m_grid_element->m_element_type == glib::SearchPath) {
                path.emplace_front(crawl);
            }
            crawl = m_predecessor.at(m_graph->get_Vector_Pos(crawl));
        }
        destination->m_grid_element->update_element(glib::FoundDestination);
        for(Node* node : path) {
            node->m_grid_element->update_element(glib::FoundPath);
            //animation delay
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    }

    Node* BreadthFirstSearch::search_For_Destination() {
        m_adjacency_queue.push_back(m_start_node);
        Node* destination_node = nullptr;
        while(!m_adjacency_queue.empty() && destination_node == nullptr) {
            destination_node = visit_Adjacent_Nodes();
            std::this_thread::sleep_for(std::chrono::microseconds(750));
        }
        return destination_node;
    }

    Node* BreadthFirstSearch::visit_Adjacent_Nodes() {
        //don't need to check start since the destination and start cant be on the same node
        Node* node = m_adjacency_queue.front();
        m_adjacency_queue.pop_front();
        int pos = m_graph->get_Vector_Pos(node);
        m_visited.at(pos) = true;
        for(auto adjacent_node : node->m_adjacency_list) {
            int adj_pos = m_graph->get_Vector_Pos(adjacent_node);
            //checks if the adjacent node is visited and continues if it is
            if(m_visited.at(adj_pos) || adjacent_node->m_grid_element->m_element_type == glib::Obstacle) continue;
            m_visited.at(adj_pos) = true;
            m_distance.at(adj_pos) = m_distance.at(pos) + 1;
            m_predecessor.at(adj_pos) = node;
            //checks if the node is at the destination if so return adjacent_node
            if(check_Is_Destination(adjacent_node)) return adjacent_node;
        }
        return nullptr;
    }

    bool BreadthFirstSearch::check_Is_Destination(Node* node) {
        auto adj_element_type = node->m_grid_element->m_element_type;
        //returns true if destination is found
        if(adj_element_type == glib::Destination) return true;
        node->m_grid_element->update_element(glib::SearchPath);
        m_adjacency_queue.push_back(node);
        return false;
    }
}
