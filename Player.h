#ifndef PLAYER_H
#define CARD_H
class Player{
    public:
        string get_name();
        Card get_hand();
        int get_wallet();
        int get_bet();

        void set_name(string name);
        void set_wallet(int value);
        void set_bet(int value)
        void hit(); // add a card to the hand


    private:
        string m_name; // what will I call you
        Card *m_hand[13]; // usual possible amount of cards
        int m_wallet; // how much money
        int m_bet; // self explanatory
}
#endif