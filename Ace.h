#ifndef ACE_H
#define ACE_H

#include "Card.h"

// Child Class Derived from Card, specifically for Ace cards
class Ace : public Card {
public:
    Ace();
    int get_value() override;
    void toggle_value() override; // toggle between 1 and 11
private:
    int m_values[2]; // Ace can be 1 or 11
    bool use_high_value; // true if using 11, false if using 1
};

#endif // ACE_H