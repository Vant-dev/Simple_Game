#pragma once
#include "Game.h"

    Game::Game(int dif, int setC, int lifeC, std::string difff, std::string set)
    : difficult(dif), setCount(setC), lifeCount(lifeC), diff(difff), sets(set) {}


    int Game::calculateScore() {
        int score = (lifeCount * 10 + difficult * 5) * setCount;
        return score;
    }

    void Game::awardBonusLife() {
        const int bonusThreshold = 50;
        int score = calculateScore();
        if (score > bonusThreshold) 
        {
            lifeCount++;
        } 
    }
    
    int Game::setDifficult(const std::string &difficulty) {
        if(difficulty.empty()) return 0;
        for (char c : difficulty) {
            if (!std::isdigit(c))
                return 0;
        }
        try {
            difficult = std::stoi(difficulty);
        } catch(...) {
            return 0;
        }
        if (difficult < 1 || difficult > 10)
            return 0;
        return difficult;
    }
    
    int Game::setsSetter(const std::string &newSets) {
        if(newSets.empty()) return 0;
        for (char c : newSets) {
            if (!std::isdigit(c))
                return 0;
        }
        try {
            setCount = std::stoi(newSets);
        } catch(...) {
            return 0;
        }
        if (setCount < 1 || setCount > 99)
            return 0;
        return setCount;
    }
    
     void Game::gameStart() {}
     void Game::gameEnd() {}

