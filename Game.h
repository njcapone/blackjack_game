#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
class Game{
    public:
        bool game_start(); // start game, create a player and a dealer
        bool deal_hand(); // deal hands for both the player and the dealer
        int judge_player(); // sum up player hand
        int judge_dealer(); // sum up dealer hand
        bool end_game(); // clear all hands, return the earnings

    private:
        Player *m_player;
        Dealer *m_dealer;
        std::string m_cardFile = "cards.txt";
        bool m_gameOn;
        bool m_playerWin;
        bool m_dealerWin;
};
#endif