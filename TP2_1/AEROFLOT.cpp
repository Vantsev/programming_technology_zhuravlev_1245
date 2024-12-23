#include "AEROFLOT.h"

// Конструктор
AEROFLOT::AEROFLOT(const std::string& destination, int flightNumber, const std::string& planeType)
        : destination(destination), flightNumber(flightNumber), planeType(planeType) {}

// Методы доступа
std::string AEROFLOT::getDestination() const { return destination; }
int AEROFLOT::getFlightNumber() const { return flightNumber; }
std::string AEROFLOT::getPlaneType() const { return planeType; }

void AEROFLOT::setDestination(const std::string& destination) { this->destination = destination; }
void AEROFLOT::setFlightNumber(int flightNumber) { this->flightNumber = flightNumber; }
void AEROFLOT::setPlaneType(const std::string& planeType) { this->planeType = planeType; }

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const AEROFLOT& flight) {
    os << "Рейс №" << flight.flightNumber << " (" << flight.planeType << ") - Пункт назначения: " << flight.destination;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, AEROFLOT& flight) {
    std::cout << "Введите пункт назначения: ";
    is >> flight.destination;
    std::cout << "Введите номер рейса: ";
    is >> flight.flightNumber;
    std::cout << "Введите тип самолета: ";
    is >> flight.planeType;
    return is;
}

// Метод для сравнения рейсов по номеру рейса (для сортировки)
bool AEROFLOT::operator<(const AEROFLOT& other) const {
    return flightNumber < other.flightNumber;
}

// Деструктор
AEROFLOT::~AEROFLOT() {}
