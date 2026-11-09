#include <iostream>
#include "Card.h"

// define the default constructor
Card::Card() : m_name(""), m_value(0), m_isAce(false) {}

// define the constructor with parameters; ace is false by default
Card::Card(std::string name, int value) : m_name(name), m_value(value) {
    m_isAce = (false);
}

Card::~Card() {
    // Destructor implementation (if needed)
}

std::string Card::get_name() {
    return m_name;
}
void Card::set_name(std::string name) {
    m_name = name;
}

int Card::get_value() {
    return m_value;
}

void Card::toggle_value() {
    // This function is intended to be overridden in derived classes (e.g., Ace)
    return; // Do nothing in the base class
}

void Card::set_value(int value) {
    m_value = value;
}

bool Card::is_ace() {
    return m_isAce;
}