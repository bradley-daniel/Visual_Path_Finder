//
// Created by Bradley Daniel on 3/4/23.
//
#include "Grid.h"
#include "GridElement.h"
#include "gLib.h"
#include <vector>

Grid::GridData::GridData(int x_max, int y_max) : m_width(x_max), m_height(y_max) {
    m_elements = std::make_unique<GridVector>(y_max, std::vector<GridElement>(x_max));
    construct_grid();
}

Grid::GridElement* Grid::GridData::get_element(int x, int y) {
    return &m_elements->at(y).at(x);
}

void Grid::GridData::add_element(int x, int y, gLib::Element_Type element_type) {
    m_elements->at(y).at(x) = GridElement(element_type, x, y);
}

void Grid::GridData::construct_grid() {
    for(int i = 0; i < m_elements->size(); i++) {
        for (int j = 0; j < m_elements->at(i).size(); j++) {
            add_element(j, i, gLib::Empty);
        }
    }
}

void Grid::GridData::clear_grid() {
    for(int i = 0; i < m_height; i++) {
        for(int j = 0; j < m_width; j++) {
            add_element(j, i, gLib::Empty);
        }
    }
}

void Grid::GridData::set_start(int x, int y) {
    m_start = {x, y};
    get_element(x, y)->update_element(gLib::Start);
}

void Grid::GridData::set_destination(int x, int y) {
    m_destination = {x, y};
    get_element(x, y)->update_element(gLib::Destination);
}
