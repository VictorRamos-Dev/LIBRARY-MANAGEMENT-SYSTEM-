/**************************************************************************************  Final Project Milestone 3
Module: NRA
Filename: Publication.cpp
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

#include <cstring>
#include <iomanip>
#include <iostream>
#include "Publication.h"

namespace sdds
{
    Publication::Publication()
    {
        defaultStter();
    }

    Publication::Publication(const Publication &publication)
    {
        *this = publication;
    }

    Publication &Publication::operator=(const Publication &publication)
    {
        set(publication.m_membership);
        setRef(publication.m_libRef);
        strcpy(m_shelfld, publication.m_shelfld);
        m_date = publication.m_date;

        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }

        if (publication.m_title != nullptr)
        {
            m_title = new char[strlen(publication.m_title) + 1];
            strcpy(m_title, publication.m_title);
        }
        else
        {
            m_title = nullptr;
        }

        return *this;
    }

    Publication::~Publication()
    {
        delete[] m_title;
    }

    void Publication::defaultStter()
    {
        m_title = nullptr;
        m_shelfld[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char *title) const
    {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(std::ios &io) const
    {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream &Publication::write(std::ostream &os) const
    {
        char title[SDDS_TITLE_WIDTH + 1] = {0};
        std::strncpy(title, m_title, SDDS_TITLE_WIDTH);

        if (conIO(os))
        {
            os << "| " << m_shelfld << " | " << std::setw(30) << std::left << std::setfill('.') << title << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else
        {
            os << type();
            os << "\t" << m_libRef << "\t" << m_shelfld << "\t" << m_title << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }

        return os;
    }

    std::istream &Publication::read(std::istream &istr)
    {
        char t_title[256]{}, t_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int t_libRef = -1, t_membership = 0;
        Date t_date;

        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        defaultStter();

        if (conIO(istr))
        {
            std::cout << "Shelf No: ";
            istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

            if (strlen(t_shelfId) != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            istr.getline(t_title, 256);

            std::cout << "Date: ";
            istr >> t_date;
        }

        else
        {
            istr >> t_libRef;
            istr.ignore();
            istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            istr.getline(t_title, 256, '\t');
            istr >> t_membership;
            istr.ignore();
            istr >> t_date;
        }

        if (!t_date)
        {
            istr.setstate(std::ios::failbit);
        }

        if (istr)
        {
            m_title = new char[strlen(t_title) + 1];
            strcpy(m_title, t_title);
            strcpy(m_shelfld, t_shelfId);
            m_membership = t_membership;
            m_date = t_date;
            m_libRef = t_libRef;
        }

        return istr;
    }

    Publication::operator bool() const
    {
        bool result = false;
        if (m_title != nullptr && m_title[0] != '\0' && m_shelfld != nullptr && m_shelfld[0] != '\0')
        {
            result = true;
        }

        return result;
    }
}
