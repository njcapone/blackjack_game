#ifndef ACE_H
#define ACE_H

#include "Card.h"

// Child Class Derved from Card, specifically for Ace cards
class Ace : public Card {
public:
    Ace();
    int get_value() override;
private:
    int m_values[2]; // Ace can be 1 or 11
};

#endif // ACE_H