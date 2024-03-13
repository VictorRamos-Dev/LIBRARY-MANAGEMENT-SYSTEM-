/**************************************************************************************  Final Project Milestone 3
Module: NRA
Filename: Publication.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"

namespace sdds
{
    class Book : public Publication
    {
    private:
        char *m_authorName;

    public:
        Book();
        ~Book();
        Book(const Book &_book);

        Book &operator=(const Book &_book);

        char type() const;

        std::ostream &write(std::ostream &os) const;

        // CLEAN
        std::istream &read(std::istream &is);

        virtual void set(int member_id);

        operator bool() const;
    };

}
#endif // SDDS_BOOK_H