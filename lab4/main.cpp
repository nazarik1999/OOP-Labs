#include <iostream>
#include "dbase.h"

int main()
{
    const int nRecord = 7;

    DBase dbase(nRecord);
    dbase.InitInput();
    dbase.Show();

    std::string specific_destination;
    std::cout << "Please input specific final destination: ";
    std::cin >> specific_destination;
    dbase.ShowObjectsWithFinalDestinationName(specific_destination);

    return 0;
}
