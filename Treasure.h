#pragma once
#ifndef TREASURE_H
#define TREASURE_H

#include "Game.h"
#include "Game.cpp"

class Treasure : public Game
{
    protected:
        static const int height = 5;
        static const int width = 5;
        int bombCount;
        int collectTreasure;
        int localLife;     
        int x, y;
        std::string X, Y;
        int maxTreasure;
        int treasureCount;
        int arr[height][width];
        int cordX[25];
        int cordY[25];
        int indexX;
        int indexY;
        int moveCount;
        int score;

    public:
        // Constructor for the Treasure class
        Treasure(int bC, int cT, int lL, int x1, int y1, int mT, int tC, int iX, int iY, int mC);

        // Check if the player has already opened this cell
        bool isOpen(int i, int j);

        // Method to fill the field with treasures
        void hideTreasure();

        // Method to perform the initial setup of the game
        void gameStart() override;

        // Getter for obtaining the value of the localLife variable
        int getLocalLife();
        
        // Getter for obtaining the collectTreasure variable
        int getCollectTreasure();

        // Getter for obtaining the maxTreasure variable
        int getMxTr();
        
        // Getter for obtaining the bombCount variable
        int getBomb();

        // Getter for obtaining the value of the moveCount variable
        int getMoveCount();

        // Getter for obtaining the value of the score variable
        int getScore();
        
        // Method implementing the main game logic
        void playTurn();
        
        // Method to get the score at the end of the game
        void gameEnd() override;

};

#endif

