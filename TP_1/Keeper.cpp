#include "Keeper.h"
#include <iostream>

Keeper::Keeper() : animals(nullptr), size(0) {
    std::cout << "Keeper constructor called." << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;
    std::cout << "Keeper destructor called." << std::endl;
}

void Keeper::addAnimal(Animal* animal) {
    Animal** newAnimals = new Animal*[size + 1];
    for (int i = 0; i < size; ++i) {
        newAnimals[i] = animals[i];
    }
    newAnimals[size] = animal;
    delete[] animals;
    animals = newAnimals;
    size++;
}

void Keeper::removeAnimal(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index for removal");
    }
    delete animals[index];
    for (int i = index; i < size - 1; ++i) {
        animals[i] = animals[i + 1];
    }
    size--;
}

void Keeper::printAnimals() const {
    for (int i = 0; i < size; ++i) {
        animals[i]->printInfo();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::ios_base::failure("Error opening file for writing");
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (int i = 0; i < size; ++i) {
        // Сохранение информации
    }
    file.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::ios_base::failure("Error opening file for reading");
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    animals = new Animal*[size];
    for (int i = 0; i < size; ++i) {
        // Восстановление информации
    }
    file.close();
}
