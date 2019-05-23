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
    in >> bus.m_bus_number;
    in >> bus.m_driver_initials;
    in >> bus.m_route_number;

    return in;
}

std::ostream& operator << (std::ostream& out, const Bus& bus)
{
    out << "Bus info: " << std::endl;
    out << "Bus number: " << bus.m_bus_number << std::endl;
    out << "Driver initials: " << bus.m_driver_initials << std::endl;
    out << "Route number: " << bus.m_route_number << std::endl;

    return out;
}

#endif // BUS_H
