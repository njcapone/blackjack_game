#include <iostream>
#include "Dealer.h"

Dealer::Dealer() : Player() {
    // Constructor implementation (if needed)
}


Card Dealer::get_first_card() {
    return *(get_hand().get_top_card()); // Return the first card in the dealer's hand
}

void Dealer::hit(Card *card) {
    // Implement the logic to add a card to the dealer's hand
    // This function should interact with the game deck to draw a card and add it to the dealer's hand
    if (get_hand().get_total_value() < 17) {
        get_hand().add_card(card); // Add the card to the dealer's hand if the total value is less than 17
    }
    else {
        get_hand().show_hand();
        std::cout << "Dealer hand now has a total value of " << get_hand().get_total_value() << std::endl;
    }
}

