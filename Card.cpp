#include <iostream>
#include "Card.h"

// define the default constructor
Card::Card() : m_name(""), m_value(0), m_isAce(false) {}

// define the constructor with parameters; ace is false by default
Card::Card(std::string name, int value, bool isAce) : m_name(name), m_value(value), m_isAce(isAce) {}

Card::~Card() {
    // Destructor implementation (if needed)
    m_next = nullptr;
    m_value = 0;
    m_name = "";
}

Card::Card(const Card &other){
    m_next = nullptr;
    m_name = other.get_name();
    m_value = other.get_value();
    m_isAce = other.is_ace();

}
std::string Card::get_name() const{
    return m_name;
}
void Card::set_name(std::string name) {
    m_name = name;
}

int Card::get_value() const{
    return m_value;
}

void Card::toggle_value() {
    if (m_isAce) {
        if (m_value == 11) {
            m_value = 1; // Toggle Ace value from 11 to 1
        } else if (m_value == 1) {
            m_value = 11; // Toggle Ace value from 1 to 11
        }
    }
}

void Card::set_value(int value) {
    m_value = value;
}

bool Card::is_ace() const {
    return m_isAce;
}