#include "Bird.h"
#include <iostream>

Bird::Bird() : Animal(), food("Unknown"), habitat("Unknown") {
    std::cout << "Bird default constructor called" << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat)
        : Animal(breed, color), food(food), habitat(habitat) {
    std::cout << "Bird parameterized constructor called" << std::endl;
}

Bird::Bird(const Bird& other)
        : Animal(other), food(other.food), habitat(other.habitat) {
    std::cout << "Bird copy constructor called" << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called" << std::endl;
}

void Bird::display() const {
    std::cout << "Bird - Breed: " << breed << ", Color: " << color << ", Food: " << food << ", Habitat: " << habitat << std::endl;
}

void Bird::setData(const std::string& breed, const std::string& color) {
    this->breed = breed;
    this->color = color;
}

std::string Bird::getFood() const {
    return food;
}

void Bird::setFood(const std::string& food) {
    this->food = food;
}

std::string Bird::getHabitat() const {
    return habitat;
}

void Bird::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}
