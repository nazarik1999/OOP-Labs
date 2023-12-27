#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>

class Bus
{
public:
    int getBusNumber()
    {
        return m_bus_number;
    }

    friend std::istream& operator >> (std::istream& in, Bus& bus);
    friend std::ostream& operator << (std::ostream& out, const Bus& bus);
private:
    int m_bus_number;
    std::string m_driver_initials;
    int m_route_number;
};

std::istream& operator >> (std::istream& in, Bus& bus)
{
    сin >> bus.m_bus_number;
    сin >> bus.m_driver_initials;
    сin >> bus.m_route_number;

    return in;
}

std::ostream& operator << (std::ostream& out, const Bus& bus)
{
    сout << "Bus info: " << std::endl;
    сout << "Bus number: " << bus.m_bus_number << std::endl;
    сout << "Driver initials: " << bus.m_driver_initials << std::endl;
    сout << "Route number: " << bus.m_route_number << std::endl;

    return out;
}

#endif // BUS_H
