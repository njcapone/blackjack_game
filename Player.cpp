#include <iostream>
#include "Player.h"

Player::Player() : m_name(""), m_wallet(50), m_hand(Hand()) {}

Player::Player(std::string name, int wallet) : m_name(name), m_wallet(wallet), m_hand(Hand()) {}

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

void Player::set_name(std::string name) {
    m_name = name;
}

void Player::set_wallet(int value) {
    m_wallet = value;
}

void Player::set_bet(int value) {
    m_bet = value;
}

Hand& Player::get_hand() {
    return m_hand;
}




