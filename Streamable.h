/**************************************************************************************  Final Project Milestone 3
Module: NRA
Filename: Streamable.h
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
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;

        virtual std::istream &read(std::istream &is) = 0;

        virtual bool conIO(std::ios &io) const = 0;

        virtual ~Streamable();

        virtual operator bool() const = 0;
    };
    std::ostream &operator<<(std::ostream &os, const Streamable &s);
    std::istream &operator>>(std::istream &is, Streamable &s);

}
#endif // SDDS_STREAMABLE_H