#ifndef CARD_H
#define CARD_H
class Card{
    public:
        string get_name();
        void set_name(string name);
        int get_value();
        void set_value(int value);
        string get_suit();
        void set_suit();

    private:
        string m_name; // the player will see this
        int m_values[2]; // ace can 11 or 1
        string m_suit; // just good to have it
}
#endif