#include "Keeper.h"
#include <iostream>
#include <fstream>

// Конструктор класса Keeper
// Выводит сообщение о том, что конструктор был вызван
Keeper::Keeper() {
    std::cout << "Keeper constructor called" << std::endl;
}

// Деструктор класса Keeper
// Освобождает память, выделенную под каждое животное в коллекции
// Выводит сообщение о том, что деструктор был вызван
Keeper::~Keeper() {
    for (Animal* animal : animals) {
        delete animal;
    }
    std::cout << "Keeper destructor called" << std::endl;
}

// Метод для добавления животного в коллекцию
// Принимает указатель на объект Animal и добавляет его в коллекцию
void Keeper::addAnimal(Animal* animal) {
    animals.push_back(animal);
}

// Метод для удаления животного из коллекции
// Пользователю предлагается выбрать тип животного (рыба, птица или кошка)
// Затем отображается список животных выбранного типа с их индексами
// Пользователю предлагается ввести индекс животного, которое нужно удалить
// Если введенный индекс действителен, то животное удаляется из коллекции
void Keeper::removeAnimal() {
    int choice;
    std::cout << "1. Remove Fish\n2. Remove Bird\n3. Remove Cat\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    int index = -1;
    switch (choice) {
        case 1:
            displayAnimalsByType("Fish");
            std::cout << "Enter the index of the Fish to remove: ";
            std::cin >> index;
            removeAnimalByType("Fish", index);
            break;
        case 2:
            displayAnimalsByType("Bird");
            std::cout << "Enter the index of the Bird to remove: ";
            std::cin >> index;
            removeAnimalByType("Bird", index);
            break;
        case 3:
            displayAnimalsByType("Cat");
            std::cout << "Enter the index of the Cat to remove: ";
            std::cin >> index;
            removeAnimalByType("Cat", index);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return;
    }
}

// Метод для отображения всех животных в коллекции
// Вызывает метод display() для каждого животного в коллекции
void Keeper::displayAnimals() const {
    for (const Animal* animal : animals) {
        animal->display();
    }
}

// Метод для отображения животных определенного типа в коллекции
// Принимает строку с типом животного (рыба, птица или кошка)
// Выводит информацию о каждом животное выбранного типа с его индексом
void Keeper::displayAnimalsByType(const std::string& type) const {
    int index = 0;
    for (const Animal* animal : animals) {
        if ((type == "Fish" && dynamic_cast<const Fish*>(animal)) ||
            (type == "Bird" && dynamic_cast<const Bird*>(animal)) ||
            (type == "Cat" && dynamic_cast<const Cat*>(animal))) {
            std::cout << index << ". ";
            animal->display();
            index++;
        }
    }
}

// Метод для удаления животного определенного типа из коллекции по индексу
// Принимает строку с типом животного (рыба, птица или кошка) и индекс животного
// Удаляет животное из коллекции, если индекс действителен
void Keeper::removeAnimalByType(const std::string& type, int index) {
    int currentIndex = 0;
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        if ((type == "Fish" && dynamic_cast<Fish*>(*it)) ||
            (type == "Bird" && dynamic_cast<Bird*>(*it)) ||
            (type == "Cat" && dynamic_cast<Cat*>(*it))) {
            if (currentIndex == index) {
                delete *it;
                animals.erase(it);
                return;
            }
            currentIndex++;
        }
    }
    std::cout << "Invalid index" << std::endl;
}

// Метод для сохранения данных о животных в файл
// Принимает имя файла в качестве аргумента
// Открывает файл для записи и записывает в него информацию о каждом животном в коллекции
// Формат записи: тип животного, порода, цвет, и дополнительные атрибуты (в зависимости от типа животного)
void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Animal* animal : animals) {
            std::string type;
            if (dynamic_cast<const Fish*>(animal)) {
                type = "Fish";
                const Fish* fish = dynamic_cast<const Fish*>(animal);
                file << type << " " << fish->getBreed() << " " << fish->getColor() << " " << fish->getDietType() << std::endl;
            }
            if (dynamic_cast<const Bird*>(animal)) {
                type = "Bird";
                const Bird* bird = dynamic_cast<const Bird*>(animal);
                file << type << " " << bird->getBreed() << " " << bird->getColor() << " " << bird->getFood() << " " << bird->getHabitat() << std::endl;
            }
            if (dynamic_cast<const Cat*>(animal)) {
                type = "Cat";
                const Cat* cat = dynamic_cast<const Cat*>(animal);
                file << type << " " << cat->getBreed() << " " << cat->getColor() << " " << cat->getOwnerName() << " " << cat->getNickname() << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for writing" << std::endl;
    }
}

// Метод для загрузки данных о животных из файла
// Принимает имя файла в качестве аргумента
// Открывает файл для чтения и считывает из него информацию о каждом животном
// Создает объект соответствующего типа (рыба, птица или кошка) и добавляет его в коллекцию
void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string type, breed, color, dietType, food, habitat, ownerName, nickname;
        while (file >> type >> breed >> color) {
            Animal* animal = nullptr;
            if (type == "Fish") {
                file >> dietType;
                animal = new Fish(breed, color, dietType);
            } else if (type == "Bird") {
                file >> food >> habitat;
                animal = new Bird(breed, color, food, habitat);
            } else if (type == "Cat") {
                file >> ownerName >> nickname;
                animal = new Cat(breed, color, ownerName, nickname);
            }
            if (animal) {
                animals.push_back(animal);
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading" << std::endl;
    }
}
