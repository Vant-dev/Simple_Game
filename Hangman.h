#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H

#include "Game.h"
#include "Game.cpp"

class Hangman : public Game
{
    protected:
         static const int M = 4;
         int wordLength;
         int life;
         int moves;
         int unknownCharacterCount;
         bool check;
         bool test;
         char charr;
         int score; // Fixed typo from 'scooore' to 'score'
         std::string len;
         std::string choice;
         int lengthArr[M];
         std::array<std::string, M> technology  = {"informatics", "computer", "processor", "bitcoin"};
         std::array<std::string, M> biology   = {"mammal", "amphibian", "cell", "family"};
         std::array<std::string, M> cooking   = {"cake", "pie", "cheesecake", "salad"};
         std::string choosedString;
         std::string word;

    public:
        // Constructors of the Hangman class
        Hangman(int wL, int l, int m, int uCC, bool c, bool t);

        Hangman(int wL, int l, int m, int uCC, bool c);
        
        // Getter for the life variable
        int getLife();

        // Getter for the unknownCharacterCount variable
        int getUCC();

        // Getter for the score variable
        int getScore();
        
        // Getter for the choosedString variable
        std::string getCS();

        // Getter for the moves variable
        int getMoves();
        
        // Method to fill the lengthArr array
        void setLength(const std::string &choice);
        
        // Method to compare the entered letter with the guessed word
        void checkWord(char character);
        
        // Method to set the length of the guessed word
        int setLn(const std::string &lenStr);
        
        // Method to choose a word
        void chooseWord();
        
        // Getter that returns the length of the word from the lengthArr array by the specified index
        int getLength(int ind);

        // Setter to set the value of the choice variable
        void setChoice(const std::string &ch);

        // Method that implements the initial setup of the game
        void gameStart() override;

        // Method to calculate the score at the end of the game
        void gameEnd() override;

        // Getter for the word variable
        std::string getWord();

};

#endif

