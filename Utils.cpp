/**************************************************************************************  Final Project Milestone 3
Module: NRA
Filename: Date.cpp
Version 1.0
Author	Victor Ramos
Revision History
-----------------------------------------------------------
Date      26/07/2023
2023/6/26  Preliminary release
2023/7/7  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Utils.h"
#include <iostream>
using namespace std;

namespace sdds
{

    int getIntInpu(int minNum, int maxNum)
    {
        int userInput;
        bool isValid = false;
        while (isValid == false)
        {
            cin >> userInput;
            if (!cin || userInput < minNum || userInput > maxNum)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                isValid = false;
            }
            else
            {
                isValid = true;
            }
        }
        return userInput;
    }

}