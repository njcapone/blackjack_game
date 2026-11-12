#include <iostream>
#include "Game.h"
#include <fstream>
#include <sstream>

/*Macros for game text & constants*/
#define askNameText "What is your name? "      
#define actionText "What would you like to do? (1) Hit (2) Stand (3) Quit: "

Game::Game() : m_player(nullptr), m_dealer(nullptr), m_gameOn(false), m_playerWin(false), m_dealerWin(false) {}

Game::~Game() {
    delete m_player; // Clean up player object
    delete m_dealer; // Clean up dealer object
}

// return true if game started successfully, false otherwise
bool Game::game_start() {
    m_player = new Player("Player", 100); // Create a player with a name and initial wallet
    m_dealer = new Dealer(); // Create a dealer
    m_gameOn = true; // Set the game state to on
    load_cards(); // Load cards helper function, not implemented yet
}
/*
Game loop steps
NOTE: Loop runs while judge() returns 0, meaning no winner yet
1. Show the player's hand and the dealer's first card
2. Ask the player if they want to hit or stand
3. If the player hits, add a card to their hand and check if they bust (>21)
4. If the player stands, let the dealer play according to the rules (hit until 17 or higher)
5. After the dealer's turn, call judge() to determine the winner
6. If the game is over, call end_game() to clear hands and return earnings

*/
bool Game::game_loop() {
    // Implement the main game loop logic here
    // This function should handle the flow of the game, including player actions, dealer actions, and determining the winner
    
    while (judge() == 0){}
}
// judge the total value of the player's hand
int Game::judge() {
    int playerValue = m_player->get_hand().get_total_value(); // Return the total value of the player's hand
    int dealerValue = m_dealer->get_hand().get_total_value(); // Return the total value of the dealer's hand

    if (playerValue > dealerValue && playerValue <= 21) {
        m_playerWin = true;
        return 1; // Player wins
    } else if (playerValue < dealerValue && dealerValue <= 21 || playerValue > 21) {
        m_dealerWin = true;
        return -1; // Dealer wins
    } else {
        return 0; // no winner yet
    }
}

void Game::load_cards() {
    // Implement the logic to load cards from the file specified in m_cardFile
    // This function should read the card data and populate m_gameDeck accordingly

    std::ifstream cardFile(m_cardFile);

    // error handling
    if (!cardFile) {
        std::cerr << "Error opening card file: " << m_cardFile << std::endl;
        return;
    } else {
        std::string line;
        while (std::getline(cardFile, line)) {
            // Parse the line to create a Card object and add it to m_gameDeck
            // Assuming the line format is suitable for creating a Card object
            // Example: "Ace of Spades" or "10 of Hearts"
            // You would need to implement the Card class and its constructor accordingly

            // For demonstration, let's assume we have a Card constructor that takes a string
            std::stringstream lineStream(line);
            std::string name;
            std::string aceStr;
            bool isAce = false;

            std::getline(lineStream, name, ','); // Assuming the name is the first part of the line
            std::getline(lineStream, aceStr, ','); // Assuming the ace string is the second part of the line
            isAce = (aceStr == "true"); // convert the ace string to a boolean value

            std::string valueStr;
            std::getline(lineStream, valueStr); // Assuming the value is the third part of the line
            int value = std::stoi(valueStr); // convert the value string to an integer
            Card* newCard = new Card(name, value); // Create a new Card object with the name and value
            m_gameDeck.add_card(newCard); // Add the card to the game deck
            
        }
    }
    return;
}