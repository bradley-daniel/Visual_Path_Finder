//
// Created by Bradley Daniel on 3/4/23.
//
#include "Grid.h"
#include "GridElement.h"
#include "glib.h"
#include <vector>

namespace grid {
    Grid::Grid(int width, int height) : m_width(width), m_height(height) {
        m_elements = std::make_unique<GridVector>(height, std::vector<GridElement>(width));
        construct_grid();
    }

    GridElement* Grid::get_element(int x, int y) {
        return &m_elements->at(y).at(x);
    }

    void Grid::add_element(int x, int y, int element_type) {
        m_elements->at(y).at(x) = GridElement(element_type, x, y);
    }

    void Grid::construct_grid() {
        for (int i = 0; i < m_elements->size(); i++) {
            for (int j = 0; j < m_elements->at(i).size(); j++) {
                add_element(j, i, glib::Empty);
            }
        }
    }

    void Grid::clear_grid() {
        for (int i = 0; i < m_height; i++) {
            for (int j = 0; j < m_width; j++) {
                add_element(j, i, glib::Empty);
            }
        }
    }

    void Grid::set_start(int x, int y) {
        m_start = {x, y};
        get_element(x, y)->update_element(glib::Start);
    }

    void Grid::set_destination(int x, int y) {
        m_destination = {x, y};
        get_element(x, y)->update_element(glib::Destination);
    }
}
