#include <iostream>
#include "Hand.h"
#include "Card.h"
Hand::Hand() : m_top(nullptr), m_cardCount(0) {}

Hand::~Hand() {
    clear_hand(); // Clear the hand when the Hand object is destroyed
}

void Hand::add_card(Card* card) {
    if (m_cardCount == 0) {
        m_top = card; // If the hand is empty, set the top card to the new card
    } else {
        card->set_next(m_top); // Set the next pointer of the new card to the current top card
        m_top = card; // Update the top card to the new card
    }
    m_cardCount++; // Increment the card count
    return;
}

Card* Hand::get_top_card() {
    return m_top; // Return the top card in the hand
}

void Hand::clear_hand() {
    while (m_top != nullptr) {
        Card* temp = m_top; // Store the current top card
        m_top = m_top->get_next(); // Move the top pointer to the next card
        delete temp; // Delete the current top card
    }
    m_cardCount = 0; // Reset the card count to zero
}

int Hand::get_total_value() {
    int valueAcesHigh = 0; // Total value considering Aces as 11
    int valueAcesLow = 0; // Total value considering Aces as 1
    Card* current = m_top; // Start from the top card
    
    while (current != nullptr) {
        if (current->is_ace()){
            valueAcesHigh += current->get_value(); // Add the value of the Ace (11)
            current->toggle_value(); // Toggle the Ace value to 1 for the low total
            valueAcesLow += current->get_value(); // Add the value of the Ace (1)
        }else{
            valueAcesHigh += current->get_value(); // Add the value of the card
            valueAcesLow += current->get_value(); // Add the value of the card
        }
        current = current->get_next(); // Move to the next card
    }
    
    // must implement logic for when high value and low value are both over 21
    
}