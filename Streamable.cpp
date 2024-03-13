/**************************************************************************************  Final Project Milestone 3
Module: NRA
Filename: Streamable..cpp
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

#include "Streamable.h"

namespace sdds
{
    Streamable::~Streamable(){};

    std::ostream &operator<<(std::ostream &os, const Streamable &s)
    {

        if (s)
        {
            s.write(os);
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Streamable &s)
    {
        return (s.read(is));
    }

}
