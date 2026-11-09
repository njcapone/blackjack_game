#ifndef HAND_H
#define HAND_H

#include "Card.h"

/* Hand Class will be implemented as a stack where the most recent
   card is always at the top of the stack */
class Hand {
    public:
        Hand(); // default constructor
        ~Hand(); // destructor
        void add_card(Card* card); // add a card to the hand
        Card* get_top_card(); // get the top card in the hand
        int get_total_value(); // get the total value of the hand
        void clear_hand(); // clear the hand

    private:
        Card* m_top; // pointer to the top card in the hand
        int m_cardCount; // number of cards in hand
};

#endif;