#pragma once
#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Treasure.h"
#include "Treasure.cpp"

class Graphic : public Treasure
{
    public:
        // Constructor of the Graphic class
        Graphic(int bC, int cT, int lL, int x1, int y1, int mT, int tC, int iX, int iY, int mC);
        
        // Method to display the game field in the game implemented in the Treasure class
        void showCell();
        
        // Method to input cell coordinates
        void setCord(const std::string &X1, const std::string &Y1);

};

#endif

