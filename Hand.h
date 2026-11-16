#ifndef HAND_H
#define HAND_H

#include "Card.h"


/* Hand Class will be implemented as a stack where the most recent
   card is always at the top of the stack */
class Hand {
    public:
        Hand(); // default constructor
        ~Hand(); // destructor
        // Note: We need a copy constructor to copy game hands whe

        void add_card(Card* card); // add a card to the hand
        Card* get_top_card(); // get the top card in the hand
        void show_top_card(); // show the top card in the hand
        void show_hand(); // show all cards in the hand
        int get_total_value(); // get the total value of the hand
        void clear_hand(); // clear the hand
        int get_size(); // get the number of cards in the hand

    private:
        Card* m_top; // pointer to the top card in the hand
        int m_cardCount; // number of cards in hand
        bool m_dealerHand; // true if this hand belongs to the dealer, false otherwise
};

#endif;