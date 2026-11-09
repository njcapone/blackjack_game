#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Player.h"
// Dealer Class, similar to Player but with no wallet or bet
class Dealer : public Player {
    public:
        Card get_hand() override; // dependent on m_showFullHand, will return either the first card or the full hand
        bool set_showFullHand(bool showFullHand); // set whether to show the full hand or not
        Card get_first_card();
        void hit() override; // add a card to the hand
    
    private:
        bool m_showFullHand;
};
#endif