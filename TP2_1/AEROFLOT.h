#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>

class AEROFLOT {
private:
    std::string destination;  // Пункт назначения
    int flightNumber;         // Номер рейса
    std::string planeType;    // Тип самолета

public:
    // Конструктор
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& planeType);

    // Методы доступа
    std::string getDestination() const;
    int getFlightNumber() const;
    std::string getPlaneType() const;

    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setPlaneType(const std::string& planeType);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& flight);

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, AEROFLOT& flight);

    // Метод для сравнения рейсов по номеру рейса (для сортировки)
    bool operator<(const AEROFLOT& other) const;

    // Деструктор
    ~AEROFLOT();
};

#endif
