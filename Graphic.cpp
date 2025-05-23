#pragma once
#include "Graphic.h"


    Graphic::Graphic(int bC, int cT, int lL, int x1, int y1, int mT,int tC, int iX, int iY, int mC): Treasure(bC, cT, lL, x1, y1, mT, tC, iX, iY, mC)
    {
        
    }

    void Graphic::showCell() {
        std::cout << "\033[2J\033[1;1H";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (isOpen(i, j))
                    std::cout << arr[i][j] << " ";
                else
                    std::cout << "x ";
            }
            std::cout << std::endl;
        }
    }

    void  Graphic::setCord(const std::string &X1, const std::string &Y1)
    {
       X = X1;
       Y = Y1;
    }