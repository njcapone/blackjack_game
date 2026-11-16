#ifndef CARD_H
#define CARD_H

#include <string>
// Card Parent Class
class Card{
    protected:
        virtual int get_value();
        virtual void toggle_value(); // only for Ace cards, toggles between 1 and 11
    public:
        Card(); // default constructor
        Card(std::string name, int value, bool isAce); // constructor with parameters, ace is false by default
        ~Card(); // destructor
        Card(const Card& other); // copy constructor
        std::string get_name() const;
        void set_name(std::string name);
        void set_value(int value);
        int get_value() const;
        bool is_ace() const; // check if card is an Ace or not
        Card* get_next() const; // get the next card in the stack 
        Card* set_next(Card* next); // set the next card in the stack
    private:
        friend class Hand; // Hand class can access private members of Card
        std::string m_name; // the player will see this
        int m_value; // ace can be11 or 1
        bool m_isAce; // true if the card is an ace, false otherwise
        Card* m_next; // pointer to the next card on the stack

};
#endif