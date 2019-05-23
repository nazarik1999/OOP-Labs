#include "bus.h"
#include <list>
#include <fstream>

void inputListOfBusesInParkFromKeyboard(std::list<Bus>& buses_in_park)
{
    int count;
    std::cout << "Please enter count of buses for input: ";
    std::cin >> count;

    std::cout << "Please input bus info in format:" << std::endl;
    std::cout << "Bus number, driver initials, route number" << std::endl;

    for (auto i = 0; i < count; ++i)
    {
        Bus bus;
        std::cout << (i + 1) << ". ";
        std::cin >> bus;
        buses_in_park.push_back(bus);
    }
}

void inputListOfBusesInParkFromFile(std::list<Bus>& buses_in_park)
{
    std::string file_name;
    std::cout << "Please enter the file name(with format .txt ): ";
    std::cin >> file_name;
    std::ifstream in;
    in.open(file_name);
    if (in.fail())
    {
        std::cout << "Error open file_name" << std::endl;
        exit(1);
    }

    while (! in.eof())
    {
        Bus bus;
        in >> bus;
        buses_in_park.push_back(bus);
    }
}

void deleteBusFromBusesInRouteAndAddInBusesInPark(const int bus_number,
          std::list<Bus>& buses_in_park,
          std::list<Bus>& buses_in_route)
{
   
    auto it = buses_in_route.begin();
    auto eit = buses_in_route.end();
    for (; it != eit; ++it)
    {
        auto bus = *it;
        if (bus_number == bus.getBusNumber())
        {
            buses_in_route.erase(it);
            buses_in_park.push_back(bus);
            std::cout << "The bus with number " << bus_number << " is in the park" << std::endl;
            return;
        }
    }
}

void deleteBusFromBusesInParkAndAddInBusesInRoute(const int bus_number,
            std::list<Bus>& buses_in_park,
            std::list<Bus>& buses_in_route)
{
    
    auto it = buses_in_park.begin();
    auto eit = buses_in_park.end();
    for (; it != eit; ++it)
    {
        auto bus = *it;
        if (bus_number == bus.getBusNumber())
        {
            buses_in_park.erase(it);
            buses_in_route.push_back(bus);
            std::cout << "The bus with number " << bus_number << " is on route" << std::endl;
            return;
        }
    }
}

int main()
{
    auto exit_flag = false;

    std::list<Bus> buses_in_route;
    std::list<Bus> buses_in_park;

    while (! exit_flag)
    {
        std::cout << std::endl;
        std::cout << "1. Input info of buses in park from keyboard" << std::endl;
        std::cout << "2. Input info of buses in park from file" << std::endl;
        std::cout << "3. Bus Departure" << std::endl;
        std::cout << "4. Bus Entry" << std::endl;
        std::cout << "5. Display info of buses in park" << std::endl;
        std::cout << "6. Display info of buses in route" << std::endl;
        std::cout << "7. Exit" << std::endl;

        char menu_number;
        std::cout << "Please enter menu number: ";
        std::cin >> menu_number;

        switch (menu_number)
        {
        case '1':
        {
            std::cout << "Input info of buses in park from keyboard" << std::endl;
            inputListOfBusesInParkFromKeyboard(buses_in_park);
        }
            break;
        case '2':
        {
            std::cout << "Input info of buses in park from file" << std::endl;
            inputListOfBusesInParkFromFile(buses_in_park);
        }
            break;
        case '3':
        {
            std::cout << "Bus Departure" << std::endl; // выезд автобуса

            if (buses_in_park.empty())
            {
                std::cout << "No bus in park" << std::endl;
            }
            else
            {
                int bus_number;
                std::cout << "Please input bus number: ";
                std::cin >> bus_number;
                deleteBusFromBusesInParkAndAddInBusesInRoute(bus_number, buses_in_park, buses_in_route);
            }

        }
            break;
        case '4':
        {

            std::cout << "Bus entry" << std::endl; // въезд автобуса
            if (buses_in_route.empty())
            {
                std::cout << "No bus in route" << std::endl;
            }
            else
            {
                int bus_number;
                std::cout << "Please input bus number: ";
                std::cin >> bus_number;
                deleteBusFromBusesInRouteAndAddInBusesInPark(bus_number, buses_in_park, buses_in_route);
            }
        }
            break;
        case '5':
        {
            std::cout << "Display info of buses in park" << std::endl;
            if (buses_in_park.empty())
            {
                std::cout << "No bus in park" << std::endl;
            }
            else
            {
                auto size = buses_in_park.size();
                std::cout << "Count of buses in the park: " << size << std::endl;
                auto it = buses_in_park.begin();
                auto eit = buses_in_park.end();
                for (; it != eit; ++it)
                {
                    auto& item = *it;
                    std::cout << item << std::endl;
                }
            }
        }
            break;
        case '6':
        {
            std::cout << "Display info of buses in route" << std::endl;
            if (buses_in_route.empty())
            {
                std::cout << "No bus in route" << std::endl;
            }
            else
            {
                auto size = buses_in_route.size();
                std::cout << "Count of buses in route: " << size << std::endl;
                auto it = buses_in_route.begin();
                auto eit = buses_in_route.end();
                for (; it != eit; ++it)
                {
                    auto& item = *it;
                    std::cout << item << std::endl;
                }
            }
        }
            break;
        case '7':
            exit_flag = true;
            break;
        default:
            break;
        }
    }

    system("pause");
    return 0;
}
