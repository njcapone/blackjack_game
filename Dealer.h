#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Player.h"
// Dealer Class, similar to Player but with no wallet or bet
class Dealer : public Player {
    public:
        Dealer(); // default constructor
        bool set_showFullHand(bool showFullHand); // set whether to show the full hand or not
        Card get_first_card();
        void hit() override; // add a card to the hand
        Hand get_hand() override; // return the hand of the dealer
    
    private:
        bool m_showFullHand;
};
#endif