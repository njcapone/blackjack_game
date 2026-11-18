#include <iostream>
#include "Game.h"
#include <fstream>
#include <sstream>
#include <string>
#include <random>

/*Macros for game text & constants*/
#define askNameText "What is your name? "      
#define actionText "What would you like to do? (1) Hit (2) Stand (3) Quit: "
#define setBetText "How much would you like to bet? (Current wallet: $"
#define invalidInputText "Invalid input. Please try again."
#define endGameText "Thanks for playing. Here's your earnings: "

Game::Game() : m_player(nullptr), m_dealer(nullptr), m_gameOn(false), m_playerWin(false), m_dealerWin(false) {}

Game::~Game() {
    m_player->get_hand().clear_hand(); // Clear the player's hand
    m_dealer->get_hand().clear_hand(); // Clear the dealer's hand
    delete m_player; // Clean up player object
    delete m_dealer; // Clean up dealer object
}

// return true if game started successfully, false otherwise
bool Game::game_start() {
    m_player = new Player("Player", 100); // Create a player with a name and initial wallet
    m_dealer = new Dealer(); // Create a dealer
    m_gameOn = true; // Set the game state to on
    load_cards(); // Load cards helper function
    return true;
}

bool Game::deal_hand(){
    if(m_player->get_hand().get_size() == 0 && m_dealer->get_hand().get_size() == 0){
        m_player->hit(get_random_card());
        m_player->hit(get_random_card());

        m_dealer->hit(get_random_card());
        m_dealer->hit(get_random_card());
        return true;
    }
    return false;
}
/*
Game loop steps
NOTE: Loop runs while judge() returns 0, meaning no winner yet
1. Show the player's hand and the dealer's first card
2. Ask the player if they want to hit or stand
3. If the player hits, add use judge() to check if the player has busted or won, and continue the loop if not
4. If the player stands, let the dealer play according to the rules (hit until 17 or higher); call judge
5. After the dealer's turn, call judge() to determine the winner
6. If the game is over, call end_game() to clear hands and return earnings
*/
bool Game::game_loop() {
    // Implement the main game loop logic here
    // This function should handle the flow of the game, including player actions, dealer actions, and determining the winner
    
    while (m_gameOn) { // Continue the loop while there is no winner and the player has money
        if(m_player->get_hand().get_size() == 0 && m_dealer->get_hand().get_size() == 0){
            deal_hand();
        }

        m_dealer->get_hand().show_top_card(); // Show the dealer's first card
        m_player->get_hand().show_hand(); // Show the player's hand
        if (m_player->get_bet() == 0) {
            // set the player's bet
            std::cout << setBetText << m_player->get_wallet() << "): ";
            int bet;
            std::cin >> bet; // Get the player's bet
            m_player->set_bet(bet); // Set the player's bet
        }

        if (m_player->get_bet() > m_player->get_wallet()) {
            std::cout << "You cannot bet more than your wallet. Please try again." << std::endl;
        }

        std::cout << actionText; // Ask the player for their action
        int action;
        std::cin >> action; // Get the player's action

        switch (action) {
            case 1: // Hit
                m_player->hit(m_gameDeck.get_top_card()); // Player hits and gets a card from the game deck
                m_dealer->hit(m_gameDeck.get_top_card()); // Dealer hits and gets a card from the game deck
                m_dealer->get_hand().show_hand(); // Show the dealer's hand
                m_player->get_hand().show_hand(); // Show the player's hand
                break;
            case 2: // Stand
                while (m_dealer->get_hand().get_total_value() < 17) { // Dealer hits until reaching 17 or higher
                    m_dealer->hit(m_gameDeck.get_top_card());
                }
                m_dealer->get_hand().show_hand(); // Show the dealer's hand
                m_player->get_hand().show_hand(); // Show the player's hand
                break;
            case 3: // Quit
                m_gameOn = false; // Set the game state to off
                return false; // Exit the game loop
            default:
                std::cout << invalidInputText << std::endl; // Handle invalid input
                break;
        }
        int result = judge(); // Call judge to determine if there is a winner after the player's action
        if(result == 1){
            std::cout << "Player wins!" << std::endl;
            m_player->set_wallet(m_player->get_wallet() + m_player->get_bet()); // Update the player's wallet
            m_player->set_bet(0); // Reset the player's bet
        } else if(result == -1){
            std::cout << "Dealer wins!" << std::endl;
            m_player->set_wallet(m_player->get_wallet() - m_player->get_bet()); // Update the player's wallet
            m_player->set_bet(0); // Reset the player's bet
        }

        std::cout << "Current wallet: $" << m_player->get_wallet() << std::endl; // Show the player's current wallet
        
        std::cout << "Do you want to play again? (1) Yes (2) No: "; // Ask the player if they want to play again
        int playAgain;
        std::cin >> playAgain;

        if (playAgain == 2) {
            m_gameOn = false; // Set the game state to off
            return false; // Exit the game loop
        } else if (playAgain == 1) {
            m_player->get_hand().clear_hand(); // Clear the player's hand for a new game
            m_dealer->get_hand().clear_hand(); // Clear the dealer's hand for a new game
            m_player->set_bet(0); // Reset the player's bet for a new game
        } else {
            std::cout << invalidInputText << std::endl; // Handle invalid input
        }

        if (m_player->get_wallet() <= 0) {
            std::cout << "You have run out of money. Game over." << std::endl;
            m_gameOn = false; // Set the game state to off
            return false; // Exit the game loop
        }
    }
}

bool Game::end_game(){
    // display earnings (wallet)
    std::cout << endGameText << m_player->get_wallet() << std::endl;
    return true;
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

// HELPERS //
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
            Card* newCard = new Card(name, value, isAce); // Create a new Card object with the name and value
            m_gameDeck.add_card(newCard); // Add the card to the game deck
            
        }
    }
    return;
}

Card* Game::get_random_card() {
    // Implement the logic to get a random card from m_gameDeck
    // This function should return a pointer to a Card object from the deck

    // generate a random number and iterate throught the deck that many times
    std::random_device rd;
    std::mt19937 gen(rd());
    int deck_size = m_gameDeck.get_size() - 1;
    int iterationsLimit = deck_size * 5; // there are about 4 - 5 decks in a game deck
    std::uniform_int_distribution<> dis(0, iterationsLimit);
    int iterate = dis(gen);

    // iterate through game deck and pull a card
    int count = 0;
    Card* current = m_gameDeck.get_top_card();
    while(count != iterate){
        if (current->get_next() == nullptr){
            current = m_gameDeck.get_top_card();
        }else{
            current = current->get_next();
        }
        count++;
    }
    Card* newCard = new Card(*current);
    return newCard;
}