//
// Created by Bradley Daniel on 3/4/23.
//
#include "Grid.h"
#include "GridElement.h"
#include "gLib.h"
#include <vector>

Grid::GridData::GridData(int y_max, int x_max) : m_width(x_max), m_height(y_max) {
    m_elements = std::make_unique<GridVector>(y_max, std::vector<GridElement>(x_max));
    construct_grid();
}

Grid::GridElement* Grid::GridData::get_element(int y, int x) {
    return &m_elements->at(y).at(x);
}

void Grid::GridData::add_element(int y, int x, gLib::Element_Type element_type) {
    m_elements->at(y).at(x) = GridElement(element_type, y, x);
}

void Grid::GridData::construct_grid() {
    for(int i = 0; i < m_elements->size(); i++) {
        for (int j = 0; j < m_elements->at(i).size(); j++) {
            add_element(i, j, gLib::Empty);
        }
    }
}

void Grid::GridData::randomize_grid() {
    clear_grid();
    for(int i = 0; i < m_elements->size(); i++) {
        for(int j = 0; j < m_elements->at(i).size(); j++) {
            if((int)random() % 3 + 1 == 1) get_element(i, j)->update_element(gLib::Obstacle);
        }
    }
    randomize_start();
    randomize_destination();
}

void Grid::GridData::clear_grid() {
    for(int i = 0; i < m_height; i++) {
        for(int j = 0; j < m_width; j++) {
            add_element(i, j, gLib::Empty);
        }
    }
}

void Grid::GridData::set_start(int y, int x) {
    m_start = {x, y};
    get_element(y, x)->update_element(gLib::Start);
}

void Grid::GridData::set_destination(int y, int x) {
    m_destination = {x, y};
    get_element(y, x)->update_element(gLib::Destination);
}

void Grid::GridData::randomize_start() {
    int x, y;
    do {
        x = (int) random() % (m_width - 1);
        y = (int) random() % (m_height - 1);
    } while(x == m_destination.m_x && y == m_destination.m_y);
    get_element(y, x)->update_element(gLib::Start);
    m_start = {x, y};
}

void Grid::GridData::randomize_destination() {
    int x, y;
    do {
        x = (int) random() % (m_width - 1);
        y = (int) random() % (m_height - 1);
    } while(x == m_start.m_x && y == m_start.m_y);
    get_element(y, x)->update_element(gLib::Destination);
    m_destination = {x, y};
}
