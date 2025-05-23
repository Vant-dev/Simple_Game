#pragma once
#include "Hangman.h"

Hangman::Hangman(int wL, int l, int m, int uCC, bool c, bool t) : Game(3, 3, 3, "1", " ") 
{
    wordLength = wL;
    life = l;
    moves = m;
    unknownCharacterCount = uCC;
    check = c;
    test = t;
}

Hangman::Hangman(int wL, int l, int m, int uCC, bool c) : Game(3, 3, 3, "1", " ")
{
    wordLength = wL;
    life = l;
    moves = m;
    unknownCharacterCount = uCC;
    check = c;
}

int Hangman::getLife()
{
    return life;
}

int Hangman::getUCC()
{
    return unknownCharacterCount;
}

int Hangman::getScore()
{
    return score; // Fixed typo from 'scooore' to 'score'
}

std::string Hangman::getCS()
{
    return choosedString;
}

int Hangman::getMoves()
{
    return moves;
}

void Hangman::setLength(const std::string &choice) {
    if (choice == "1")
        for (int i = 0; i < M; i++)
            lengthArr[i] = technology[i].size();
    else if (choice == "2")
        for (int i = 0; i < M; i++)
            lengthArr[i] = biology[i].size();
    else if (choice == "3")
        for (int i = 0; i < M; i++)
            lengthArr[i] = cooking[i].size();
}

void Hangman::checkWord(char character) {
    check = false;
    for (size_t i = 0; i < choosedString.size(); i++) {
        if (choosedString[i] == character) {
            word[i] = character;
            unknownCharacterCount--;
            check = true;
        }
    }
    if (!check)
        life--;
    moves++;
}

int Hangman::setLn(const std::string &lenStr) {
    if(lenStr.empty()) return 0;
    for (char m : lenStr)
        if (!std::isdigit(m))
            return 0;
    try {
        wordLength = std::stoi(lenStr);
    } catch(...) {
        return 0;
    }
    for (int i = 0; i < M; i++) {
        if (lengthArr[i] == wordLength)
            test = true;
    }
    if (!test)
        return 0;
    else {
        test = false;
        return wordLength;
    }
}

// chooseWord sets a random word from the chosen category
void Hangman::chooseWord() 
{
    choosedString = "";
    if (choice == "1") {
        while (choosedString.size() != static_cast<size_t>(wordLength))
            choosedString = technology[rand() % M];
    } else if (choice == "2") {
        while (choosedString.size() != static_cast<size_t>(wordLength))
            choosedString = biology[rand() % M];
    } else {
        while (choosedString.size() != static_cast<size_t>(wordLength))
            choosedString = cooking[rand() % M];
    }
    word = std::string(choosedString.size(), '*');
    unknownCharacterCount = choosedString.size();
}

int Hangman::getLength(int ind)
{
    return lengthArr[ind];
}

void Hangman::setChoice(const std::string &ch)
{
    choice = ch;
}

// gameStart performs setup: 
// category selection, length selection, and word guessing.
void Hangman::gameStart() 
{
    for(int i = 0; i < M; i++)
    {
        lengthArr[i] = 0;
    }
    word = "";
    wordLength = 4;
    moves = 0;
    unknownCharacterCount = 0;
    check = false;
    test = false;
    len = "";
    choosedString = "";

    setLength(choice);
}

void Hangman::gameEnd()  {
    score = calculateScore(); // Fixed typo from 'scooore' to 'score'
    awardBonusLife();
}

std::string Hangman::getWord()
{
    return word;
}

