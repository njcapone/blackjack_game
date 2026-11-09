#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"

class Player{
    public:
        Player(); // default constructor
        Player(std::string name, int wallet); // constructor with parameters
        std::string get_name();
        Card get_hand();
        int get_wallet();
        int get_bet();

        void set_name(std::string name);
        void set_wallet(int value);
        void set_bet(int value);
        void hit(); // add a card to the hand


    private:
        std::string m_name; // what will I call you
        Card *m_hand[13]; // usual possible amount of cards
        int m_wallet; // how much money
        int m_bet; // self explanatory
};
#endif