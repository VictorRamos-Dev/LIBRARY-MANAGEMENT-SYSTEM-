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

//
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds
{
    class Publication : public Streamable
    {
    private:
        char *m_title;
        char m_shelfld[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();

        ~Publication();

        Publication(const Publication &publication);

        Publication &operator=(const Publication &publication);

        void defaultStter();

        virtual void set(int member_id);

        void setRef(int value);

        void resetDate();

        virtual char type() const;

        bool onLoan() const;

        Date checkoutDate() const;

        bool operator==(const char *title) const;

        operator const char *() const;

        int getRef() const;

        bool conIO(std::ios &io) const;
        // CLEAN
        std::ostream &write(std::ostream &os) const;
        // CLEAN
        std::istream &read(std::istream &istr);

        operator bool() const;
    };
}

#endif // SDDS_PUBLICATION_H