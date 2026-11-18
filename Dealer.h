#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Player.h"
// Dealer Class, similar to Player but with no wallet or bet
class Dealer : public Player {
    public:
        Dealer(); // default constructor
        ~Dealer();
        Card get_first_card();
        
};
#endif