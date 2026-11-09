#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
#include "Hand.h"

class Player{
    public:
        Player(); // default constructor
        Player(std::string name, int wallet); // constructor with parameters
        std::string get_name();
        int get_wallet();
        int get_bet();

        void set_name(std::string name);
        void set_wallet(int value);
        void set_bet(int value);
        virtual void hit(); // add a card to the hand


    private:
        std::string m_name; // what will I call you
        Hand m_hand;
        int m_wallet; // how much money
        int m_bet; // self explanatory
};
#endif