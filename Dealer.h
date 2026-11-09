#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
class Dealer{
    public:
        Card get_hand();
        Card get_first_card();

        void hit(); // add a card to the hand
    
    private:
        Card *m_hand[13];
};
#endif