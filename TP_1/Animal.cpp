#include "Animal.h"

Animal::Animal() : breed("Unknown"), color("Unknown") {
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string& breed, const std::string& color)
        : breed(breed), color(color) {
    std::cout << "Animal constructor with parameters called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

void Animal::setBreed(const std::string& breed) {
    this->breed = breed;
}

std::string Animal::getBreed() const {
    return breed;
}

void Animal::setColor(const std::string& color) {
    this->color = color;
}

std::string Animal::getColor() const {
    return color;
}
