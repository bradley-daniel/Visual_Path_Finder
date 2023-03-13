//
// Created by Bradley Daniel on 3/6/23.
//
#include "GridElement.h"
#include "lib.h"


namespace grid {
    GridElement::GridElement(int element_type, int x, int y) : m_element_type(element_type), m_coords({x, y}), m_element(' ') {}
    GridElement::GridElement() : m_element_type(lib::Empty), m_element(lib::get_element_char(lib::Empty)) {}
    void GridElement::update_element(int new_element_type) {
        m_element_type = new_element_type;
        m_element = lib::get_element_char(new_element_type);
    }
}