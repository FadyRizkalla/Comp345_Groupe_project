//
// Created by Elisa on 2025-02-16.
//


#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

void Player::setPlayerFunds(double x){
     playerFunds = x;
}

double Player::getPlayerFunds(){
  return playerFunds;
}


void Player::displayPlayerFunds(){
  ofstream("Logs.txt", std::ios::app) << "Player has: " << playerFunds << " gold!" << endl;
}

void Player::subtractPlayerFunds(double x){
  playerFunds -= x;
}

bool Player::hasEnoughFunds(double x){
  return playerFunds >= x;
}

