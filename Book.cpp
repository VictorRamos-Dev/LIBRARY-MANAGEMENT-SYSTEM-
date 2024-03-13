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

#include "Book.h"
#include <cstring>
#include <iostream>
#include <iomanip>
namespace sdds
{

    Book::Book() : Publication()
    {
        m_authorName = nullptr;
    }

    Book::Book(const Book &_book) : Publication(_book)
    {
        // if (this != &_book)
        // {
        //     if (_book.m_authorName && _book.m_authorName[0] != '\0')
        //     {
        //         m_authorName = new char[strlen(_book.m_authorName) + 1];
        //         strcpy(m_authorName, _book.m_authorName);
        //     }
        // }

        if (m_authorName)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }
        m_authorName = new char[strlen(_book.m_authorName) + 1];
        strcpy(m_authorName, _book.m_authorName);
    }

    Book::~Book()
    {
        delete[] m_authorName;
    }

    Book &Book::operator=(const Book &_book)
    {
        Publication::operator=(_book);
        // if (this != &_book)
        // {
        //     if (_book.m_authorName && _book.m_authorName != '\0')
        //     {
        //         if (m_authorName)
        //         {
        //             delete[] m_authorName;
        //         }
        //         else
        //         {
        //             m_authorName = new char[strlen(_book.m_authorName) + 1];
        //             strcpy(m_authorName, _book.m_authorName);
        //         }
        //     }
        // }
        if (m_authorName)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        if (_book.m_authorName)
        {
            m_authorName = new char[strlen(_book.m_authorName) + 1];
            strcpy(m_authorName, _book.m_authorName);
        }
        return *this;
    }

    char Book::type() const
    {
        return 'B';
    }

    std::ostream &Book::write(std::ostream &os) const
    {
        Publication::write(os);
        if (conIO(os))
        {
            char author[SDDS_AUTHOR_WIDTH + 1] = {0};
            std::strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
            os << " ";
            os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << author << " |";
        }
        else
        {
            os << "\t" << m_authorName;
        }

        return os;
    }

    std::istream &Book::read(std::istream &is)
    {
        char author[256] = {0};

        Publication::read(is);

        if (m_authorName)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        if (conIO(is))
        {
            is.ignore();
            std::cout << "Author: ";
        }
        else
        {
            is.ignore(1000, '\t');
        }

        is.get(author, 256);

        if (is)
        {
            m_authorName = new char[strlen(author) + 1];
            strcpy(m_authorName, author);
        }
        return is;
    }

    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const
    {
        return m_authorName && Publication::operator bool();
    }

}
