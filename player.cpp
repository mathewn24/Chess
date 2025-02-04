#include "player.h"
#include <iostream>
#include <algorithm>

using namespace std;

Player::Player(string name, Color color) {
    this->name = name;
    this->color = color;
}

string Player::getName() const {
    return name;
}

Color Player::getColor() const {
    return color;
}

int Player::getPieceCount() const {
    return (int) pieces.size();
}

Piece* Player::getPiece(int i) const {
    // Get the piece indexed at i from the pieces vector
    return pieces.at(i);
}

void Player::addPiece(Piece* p) {
    // Add p to the pieces vector
    pieces.push_back(p);
}

void Player::delPiece(Piece* p) {
    // Remove p from the pieces vector
    auto it = std::find(pieces.begin(), pieces.end(), p); 
    if(it != pieces.end()) {
        pieces.erase(it);
    }
}
