#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <fstream>

Keeper::Keeper() {
    std::cout << "Keeper constructor called" << std::endl;
}

Keeper::~Keeper() {
    for (Animal* animal : animals) {
        delete animal;
    }
    std::cout << "Keeper destructor called" << std::endl;
}

void Keeper::addAnimal(Animal* animal) {
    animals.push_back(animal);
}

void Keeper::removeAnimal(int index) {
    if (index >= 0 && index < animals.size()) {
        delete animals[index];
        animals.erase(animals.begin() + index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Keeper::displayAnimals() const {
    for (const Animal* animal : animals) {
        animal->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Animal* animal : animals) {
            std::string type;
            if (dynamic_cast<const Fish*>(animal)) {
                type = "Fish";
                const Fish* fish = dynamic_cast<const Fish*>(animal);
                file << type << " " << fish->getBreed() << " " << fish->getColor() << " " << fish->getDietType() << std::endl;
            } else if (dynamic_cast<const Bird*>(animal)) {
                type = "Bird";
                const Bird* bird = dynamic_cast<const Bird*>(animal);
                file << type << " " << bird->getBreed() << " " << bird->getColor() << " " << bird->getFood() << " " << bird->getHabitat() << std::endl;
            } else if (dynamic_cast<const Cat*>(animal)) {
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
