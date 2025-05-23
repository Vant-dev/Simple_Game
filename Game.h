#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <locale>
#include <ctime>
#include <limits>
#include <array>
#include <cstdlib>
#include <cctype>

class Game
{
    protected:
         int difficult; // Difficulty level
         int setCount;  // Number of remaining rounds
         int lifeCount; // Number of lives

         std::string diff; // Variable for checking difficulty input
         std::string sets; // Variable for checking the number of sets input
    
    public:
        // Constructor for the Game class
        Game(int dif, int setC, int lifeC, std::string difff, std::string set);

        // Method for calculating the results of a round
        int calculateScore();
        
        // Method for awarding bonus lives
        void awardBonusLife();
        
        // Setter for the difficult variable
        int setDifficult(const std::string &diff);

        // Setter for the sets variable
        int setsSetter(const std::string &sets);

        // Virtual method overridden in derived classes
        virtual void gameStart() = 0;

        // Virtual method overridden in derived classes
        virtual void gameEnd() = 0;
};

#endif

