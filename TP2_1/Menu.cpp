#include "Menu.h"
#include "AEROFLOT.h"
#include <iostream>
#include <vector>
#include <set>  // Для хранения уникальных пунктов назначения
#include <algorithm>  // Для std::sort

// Сортировка рейсов по номеру рейса
bool compareByFlightNumber(const AEROFLOT& flight1, const AEROFLOT& flight2) {
    return flight1.getFlightNumber() < flight2.getFlightNumber();
}

// Вспомогательная функция для вывода всех уникальных пунктов назначения
void showDestinations(const std::vector<AEROFLOT>& flights) {
    std::set<std::string> destinations;  // Используем set для уникальности
    for (const auto& flight : flights) {
        destinations.insert(flight.getDestination());
    }

    if (destinations.empty()) {
        std::cout << "Нет доступных пунктов назначения.\n";
    } else {
        std::cout << "Существующие пункты назначения:\n";
        for (const auto& destination : destinations) {
            std::cout << "- " << destination << "\n";
        }
    }
}

void printMenu() {
    std::cout << "1) Добавить рейс\n";
    std::cout << "2) Удалить рейс\n";
    std::cout << "3) Редактировать рейс\n";
    std::cout << "4) Показать рейсы по пункту назначения\n";
    std::cout << "5) Выход\n";
}

void addFlight(std::vector<AEROFLOT>& flights) {
    std::string destination, planeType;
    int flightNumber;

    // Показываем все уникальные пункты назначения перед вводом
    showDestinations(flights);

    std::cout << "Введите пункт назначения: ";
    std::cin >> destination;
    std::cout << "Введите номер рейса: ";
    std::cin >> flightNumber;
    std::cout << "Введите тип самолета: ";
    std::cin >> planeType;

    flights.push_back(AEROFLOT(destination, flightNumber, planeType));
}

void removeFlight(std::vector<AEROFLOT>& flights) {
    int flightNumber;
    std::cout << "Введите номер рейса для удаления: ";
    std::cin >> flightNumber;

    // Используем итератор для поиска рейса по номеру
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            flights.erase(it);
            std::cout << "Рейс №" << flightNumber << " удален.\n";
            return;
        }
    }
    std::cout << "Рейс с номером " << flightNumber << " не найден.\n";
}

void editFlight(std::vector<AEROFLOT>& flights) {
    int flightNumber;
    std::cout << "Введите номер рейса для редактирования: ";
    std::cin >> flightNumber;

    // Поиск рейса с помощью итератора
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            std::string destination, planeType;
            std::cout << "Введите новый пункт назначения: ";
            std::cin >> destination;
            std::cout << "Введите новый тип самолета: ";
            std::cin >> planeType;

            it->setDestination(destination);
            it->setPlaneType(planeType);
            std::cout << "Данные рейса обновлены.\n";
            return;
        }
    }
    std::cout << "Рейс с номером " << flightNumber << " не найден.\n";
}

void showFlightsByDestination(std::vector<AEROFLOT>& flights) {
    showDestinations(flights);
    std::string destination;
    std::cout << "Введите пункт назначения: ";
    std::cin >> destination;

    // Сортируем рейсы по номеру рейса
    std::sort(flights.begin(), flights.end(), compareByFlightNumber);

    // Вывод всех рейсов по пункту назначения
    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            std::cout << "Рейс №" << flight.getFlightNumber() << " - Тип самолета: "
                      << flight.getPlaneType() << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Рейсы в " << destination << " не найдены.\n";
    }
}