#include <iostream>
#include "Ace.h"

Ace::Ace() : Card("", 1), use_high_value(true) {
    m_values[0] = 1;  // Low value
    m_values[1] = 11; // High value
}

int Ace::get_value() {
    if (use_high_value) {
        return m_values[1]; // Return high value (11)
    } else {
        return m_values[0]; // Return low value (1)
    }
}

void Ace::toggle_value() {
    use_high_value = !use_high_value;
}
 