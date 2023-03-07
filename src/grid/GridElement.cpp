//
// Created by Bradley Daniel on 3/6/23.
//
#include "GridElement.h"


Grid::GridElement::GridElement(gLib::Element_Type element_type, int y, int x) : m_element_type(element_type), m_coords({x, y}), m_element(' ') {}

Grid::GridElement::GridElement() : m_element_type(gLib::Empty), m_element(gLib::get_element_char(gLib::Empty)){}

void Grid::GridElement::update_element(gLib::Element_Type new_element_type) {
    m_element_type = new_element_type;
    m_element = gLib::get_element_char(new_element_type);
}