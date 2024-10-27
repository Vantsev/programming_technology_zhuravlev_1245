#include "Animal.h"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& breed, const std::string& color)
        : breed(breed), color(color) {
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
        : breed(other.breed), color(other.color) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getBreed() const {
    return breed;
}

std::string Animal::getColor() const {
    return color;
}
