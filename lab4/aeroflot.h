#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <string>

class Aeroflot
{
public:
    std::string getFinalDestinationName() const { return m_final_destination_name; }
    int getFlightNumber() const { return m_flight_number; }
    std::string getPlaneType() const { return m_plane_type; }

    Aeroflot& operator =(const Aeroflot& other);

    friend std::istream& operator >>(std::istream&, Aeroflot&);
    friend std::ostream& operator <<(std::ostream&, const Aeroflot&);

private:
    std::string m_final_destination_name; // название пункта назначения
    int m_flight_number; // номер рейса
    std::string m_plane_type; // тип самолета
};

Aeroflot& Aeroflot::operator =(const Aeroflot& other)
{
    m_final_destination_name = other.m_final_destination_name;
    m_flight_number = other.m_flight_number;
    m_plane_type = other.m_plane_type;
    return *this;
}

std::istream& operator >>(std::istream& in, Aeroflot& obj)
{
    сin >> obj.m_final_destination_name;
    сin >> obj.m_flight_number;
    сin >> obj.m_plane_type;
    return in;
}

std::ostream& operator <<(std::ostream& out, const Aeroflot& obj)
{
    сout << obj.m_final_destination_name << ' ';
    сout << obj.m_flight_number << ' ';
    сout << obj.m_plane_type << ' ';
    return out;
}

#endif // AEROFLOT_H
