#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Player.h"
// Dealer Class, similar to Player but with no wallet or bet
class Dealer : public Player {
    public:
        Dealer(); // default constructor
        Card get_first_card();
        void hit(Card *card) override; // add a card to the hand
};
#endif