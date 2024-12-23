# Программа для управления рейсами авиакомпании

Эта программа предназначена для управления рейсами авиакомпании. Каждый рейс представлен объектом класса `AEROFLOT`, который содержит информацию о рейсе: пункт назначения, номер рейса и тип самолета. Программа позволяет добавлять, удалять, редактировать рейсы, а также искать рейсы по пункту назначения.

## Структура программы

Программа состоит из нескольких файлов:

- **AEROFLOT.h** — Заголовочный файл, содержащий описание класса `AEROFLOT`.
- **AEROFLOT.cpp** — Реализация класса `AEROFLOT`.
- **Menu.h** — Заголовочный файл с функциями для работы с меню.
- **Menu.cpp** — Реализация функций для работы с меню.
- **main.cpp** — Основной файл программы, содержащий цикл с меню.

## Описание классов и функций

### 1. Класс `AEROFLOT`

Класс `AEROFLOT` представляет информацию о рейсе, включающую:

- Пункт назначения рейса
- Номер рейса
- Тип самолета

#### Методы класса `AEROFLOT`

- **Конструкторы**:
    - `AEROFLOT(const std::string& destination, int flightNumber, const std::string& planeType)` — создает объект рейса с заданными значениями.

- **Методы доступа (геттеры)**:
    - `std::string getDestination() const` — возвращает пункт назначения рейса.
    - `int getFlightNumber() const` — возвращает номер рейса.
    - `std::string getPlaneType() const` — возвращает тип самолета.

- **Методы изменения значений (сеттеры)**:
    - `void setDestination(const std::string& destination)` — устанавливает пункт назначения рейса.
    - `void setFlightNumber(int flightNumber)` — устанавливает номер рейса.
    - `void setPlaneType(const std::string& planeType)` — устанавливает тип самолета.

- **Перегрузка операторов**:
    - `friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& flight)` — перегрузка оператора вывода для печати информации о рейсе.
    - `friend std::istream& operator>>(std::istream& is, AEROFLOT& flight)` — перегрузка оператора ввода для ввода данных рейса.
    - `bool operator<(const AEROFLOT& other) const` — перегрузка оператора сравнения для сортировки рейсов по номеру рейса.

- **Деструктор**:
    - `~AEROFLOT()` — деструктор класса, который очищает память, если это необходимо.

### 2. Функции для работы с меню

Меню программы позволяет пользователю выполнять различные действия с рейсами:

- **void printMenu()** — выводит на экран меню с доступными опциями.
- **void addFlight(std::vector<AEROFLOT>& flights)** — добавляет новый рейс в систему. Рейс вводится с клавиатуры.
- **void removeFlight(std::vector<AEROFLOT>& flights)** — удаляет рейс по номеру. Если рейс с таким номером найден, он удаляется из списка.
- **void editFlight(std::vector<AEROFLOT>& flights)** — редактирует информацию о рейсе по номеру. Если рейс с таким номером найден, его данные обновляются.
- **void showFlightsByDestination(const std::vector<AEROFLOT>& flights)** — выводит на экран все рейсы в заданный пункт назначения, отсортированные по номеру рейса.

### 3. Основная программа

**main.cpp** реализует цикл с меню, который позволяет пользователю выбрать одну из опций:

1. Добавить рейс
2. Удалить рейс
3. Редактировать рейс
4. Показать рейсы по пункту назначения
5. Выход

## Установка

1. Клонируйте репозиторий:

    ```sh
    git clone https://github.com/Vantsev/programming_technology_zhuravlev_1245.git
    ```

2. Перейдите в каталог проекта:

    ```sh
    cd programming_technology_zhuravlev_1245/TP2_1
    ```

3. Скомпилируйте проект с помощью компилятора C++ (например, g++):

    ```sh
    g++ -std=c++11 -o aeroflot main.cpp AEROFLOT.cpp Menu.cpp
    ```

4. Запуск программы:

    ```sh
    ./aeroflot
    ```

