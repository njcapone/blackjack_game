#include <iostream>
#include "Player.h"

Player::Player() : m_name(""), m_wallet(50) {}

Player::Player(std::string name, int wallet) : m_name(name), m_wallet(wallet) {}

Player::~Player() {} // here just in case

std::string Player::get_name() {
    return m_name;
}

int Player::get_wallet() {
    return m_wallet;
}

int Player::get_bet() {
    return m_bet;
}



