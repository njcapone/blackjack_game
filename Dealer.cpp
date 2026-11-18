#include <iostream>
#include "Dealer.h"

Dealer::Dealer() : Player() {
    // Constructor implementation (if needed)
}

Dealer::~Dealer() {}

Card Dealer::get_first_card() {
    return *(get_hand().get_top_card()); // Return the first card in the dealer's hand
}



