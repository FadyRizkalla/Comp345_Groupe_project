//
// Created by Elisa on 2025-02-16.
//


#include "Player.h"
#include <iostream>
using namespace std;

void Player::setPlayerFunds(double x){
     playerFunds = x;
}

double Player::getPlayerFunds(){
  return playerFunds;
}


void Player::displayPlayerFunds(){
  cout << "Player has: " << playerFunds << " gold!" << endl;
}

void Player::subtractPlayerFunds(double x){
  playerFunds -= x;
}

bool Player::hasEnoughFunds(double x){
  return playerFunds >= x;
}

