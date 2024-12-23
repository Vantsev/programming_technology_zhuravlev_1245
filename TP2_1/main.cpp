#include <iostream>
#include <vector>
#include "AEROFLOT.h"
#include "Menu.h"

int main() {
    std::vector<AEROFLOT> flights;
    int choice;

    while (true) {
        printMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addFlight(flights);
                break;
            case 2:
                removeFlight(flights);
                break;
            case 3:
                editFlight(flights);
                break;
            case 4:
                showFlightsByDestination(flights);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
