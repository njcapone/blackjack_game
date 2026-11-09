#ifndef CARD_H
#define CARD_H

#include <string>
// Card Parent Class
class Card{
    public:
        Card(); // default constructor
        Card(std::string name, int value); // constructor with parameters
        std::string get_name();
        void set_name(std::string name);
        virtual int get_value();
        void set_value(int value);
        bool is_ace(); // check if card is an Ace or not


    private:
        std::string m_name; // the player will see this
        int m_value; // ace can 11 or 1
        bool m_isAce; // true if the card is an ace, false otherwise

};
#endif