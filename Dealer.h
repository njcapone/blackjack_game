#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Player.h"
// Dealer Class, similar to Player but with no wallet or bet
class Dealer : public Player {
    public:
        Card get_hand() override;
        Card get_first_card();

        void hit() override; // add a card to the hand
    
    private:
        Card *m_hand[13];
        bool m_showFullHand;
};
#endif