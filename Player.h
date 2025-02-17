//
// Created by Elisa on 2025-02-16.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
    private:
    double playerFunds;

    public:
    void setPlayerFunds(double funds);
    double getPlayerFunds();
    void displayPlayerFunds();
    void subtractPlayerFunds(double amount);
    bool hasEnoughFunds(double amount);

};



#endif //PLAYER_H
