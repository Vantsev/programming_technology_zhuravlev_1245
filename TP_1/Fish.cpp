#include "Fish.h"
#include <iostream>

Fish::Fish() : Animal(), dietType("Unknown") {
    std::cout << "Fish default constructor called" << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& dietType)
        : Animal(breed, color), dietType(dietType) {
    std::cout << "Fish parameterized constructor called" << std::endl;
}

Fish::Fish(const Fish& other)
        : Animal(other), dietType(other.dietType) {
    std::cout << "Fish copy constructor called" << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called" << std::endl;
}

void Fish::display() const {
    std::cout << "Fish - Breed: " << breed << ", Color: " << color << ", Diet Type: " << dietType << std::endl;
}

void Fish::setData(const std::string& breed, const std::string& color) {
    this->breed = breed;
    this->color = color;
}

std::string Fish::getDietType() const {
    return dietType;
}

void Fish::setDietType(const std::string& dietType) {
    this->dietType = dietType;
}
