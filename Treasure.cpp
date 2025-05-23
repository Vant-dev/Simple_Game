#pragma once
#include "Treasure.h"

Treasure::Treasure(int bC, int cT, int lL, int x1, int y1, int mT, int tC, 
                   int iX, int iY, int mC) : Game(3, 3, 3, "1", " ") 
{
    bombCount = bC;
    collectTreasure = cT;
    localLife = lL;
    x = x1;
    y = y1;
    maxTreasure = mT;
    treasureCount = tC;
    indexX = iX;
    indexY = iY;
    moveCount = mC;
}

bool Treasure::isOpen(int i, int j) {
    for (int k = 0; k < indexX; k++) {
        if (cordX[k] == i && cordY[k] == j)
            return true;
    }
    return false;
}

// Helper method to fill the field with treasures
void Treasure::hideTreasure()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) 
        {
            if (arr[i][j] != 2) 
            {
                if (treasureCount < difficult) 
                {
                    arr[i][j] = rand() % 2;
                    if (arr[i][j] == 1)
                    {
                        treasureCount++;
                    }
                }
            }
        }
    }
}

// gameStart performs the initial setup of the round: 
// input difficulty, initialize the field, and place bombs.
void Treasure::gameStart() {
    // Reset round variables
    bombCount = 0;
    collectTreasure = 0;
    localLife = 3;
    indexX = indexY = moveCount = treasureCount = 0;
    
    // Initialize the field (reset the array)
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            arr[i][j] = 0;
    
    maxTreasure = difficult;
    
    // Place bombs (value 2 indicates a bomb)
    while (bombCount < difficult) {
        x = rand() % height;
        y = rand() % width;
        if (arr[x][y] == 0) {
            arr[x][y] = 2;
            bombCount++;
        }
    }
    bombCount = 0; // for statistics
}

// playTurn – processes one user turn.
int Treasure::getLocalLife()
{
    return localLife;
}

int Treasure::getCollectTreasure()
{
    return collectTreasure;
}

int Treasure::getMxTr()
{
    return maxTreasure;
}

int Treasure::getBomb()
{
    return bombCount;
}

int Treasure::getMoveCount()
{
    return moveCount;
}

int Treasure::getScore()
{
    return score; // Fixed typo from 'scoore' to 'score'
}

void Treasure::playTurn() 
{
    x = std::atoi(X.c_str());
    y = std::atoi(Y.c_str());
    
    // Check the validity of the coordinates (not implemented in detail)
    if(x >= 0 && x < height && y >= 0 && y < width) 
    {
        if(arr[x][y] == 2) {
            if (!isOpen(x, y)) 
            {
                localLife--;
                bombCount++;
                cordX[indexX] = x;
                cordY[indexY] = y;
                indexX++; indexY++;
                moveCount++;
            }
        } else if (arr[x][y] == 1) {
            if (!isOpen(x, y)) 
            {
                collectTreasure++;
                cordX[indexX] = x;
                cordY[indexY] = y;
                indexX++; indexY++;
                moveCount++;
            } 
        } 
        else 
        {
            cordX[indexX] = x;
            cordY[indexY] = y;
            indexX++; indexY++;
            moveCount++;
        }
    }
}

// gameEnd outputs the results of the round
void Treasure::gameEnd()
{
    score = calculateScore(); // Fixed typo from 'scoore' to 'score'
    awardBonusLife();
}
