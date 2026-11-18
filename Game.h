#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
#include "Hand.h"

class Game{
    public:
        Game(); 
        ~Game();// default constructor
        bool game_start(); // start game, create a player and a dealer
        bool deal_hand(); // deal hands for both the player and the dealer
        bool game_loop();
        int judge(); // determine the winner of the game
        bool end_game(); // clear all hands, return the earnings

    private:
        Player *m_player;
        Dealer *m_dealer;
        std::string m_cardFile = "cards.txt";
        bool m_gameOn;
        bool m_playerWin;
        bool m_dealerWin;

        Hand m_gameDeck; // the deck of cards for the game, will be loaded and shuffled at the start of the game

        // helper functions
        void load_cards(); // load cards from file
        void betting(); // handle betting system
        void action(); // handle player actions
        
        // need a get random card function to get a random card from the deck
        Card* get_random_card(); // get a random card from the deck 
};
#endif