#ifndef DBASE_H
#define DBASE_H

#include "aeroflot.h"

class DBase
{
public:
    DBase(int);
    ~DBase();
    void InitInput();
    void Show();
    void ShowObjectsWithFinalDestinationName(const std::string finalDestination);
private:
    Aeroflot* m_aeroflots;
    int nRecords;
};

DBase::DBase(int nRec)
    : m_aeroflots(new Aeroflot[nRec])
    , nRecords(nRec)
{}

DBase::~DBase() { if (m_aeroflots) delete [] m_aeroflots; }

void DBase::InitInput()
{
    std::cout << "\nPlease input values in format: " << std::endl;
    std::cout << "Final destination name, flight number, plane type" << std::endl;
    for (auto i = 0; i < nRecords; ++i)
    {
        std::cout << (i + 1) << ". ";
        std::cin >> m_aeroflots[i];
    }

    for (auto i = 0; i < nRecords - 1; ++i)
    {
        for (auto j = 0; j < nRecords - i - 1; ++j)
        {
            if (m_aeroflots[j].getFlightNumber() > m_aeroflots[j + 1].getFlightNumber())
            {
                auto temp = m_aeroflots[j];
                m_aeroflots[j] = m_aeroflots[j + 1];
                m_aeroflots[j + 1] = temp;
            }
        }
    }
}

void DBase::Show()
{
    std::cout << "=========================" <<std::endl;
    std::cout << "Show content:" << std::endl;
    for (auto i = 0; i < nRecords; ++i)
    {
        std::cout << (i + 1) << ". " << m_aeroflots[i] << std::endl;
    }
}

void DBase::ShowObjectsWithFinalDestinationName(const std::string finalDestination)
{
    auto not_found = true;
    std::cout << "\nShow items with final destination " << finalDestination << std::endl;
    for (auto i = 0; i < nRecords; ++i)
    {
        if (m_aeroflots[i].getFinalDestinationName() == finalDestination)
        {
            std::cout << m_aeroflots[i].getFlightNumber() << " "
                      << m_aeroflots[i].getPlaneType() << std::endl;
            not_found = false;
        }
    }

    if (not_found)
    {
        std::cout << "Aeroflots not found" << std::endl;
    }
}

#endif // DBASE_H
