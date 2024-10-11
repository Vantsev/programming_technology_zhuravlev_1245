#include "Fish.h"

Fish::Fish() : Animal(), foodType("Unknown") {
    std::cout << "Fish default constructor called." << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& foodType)
        : Animal(breed, color), foodType(foodType) {
    std::cout << "Fish constructor with parameters called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::printInfo() const {
    std::cout << "Fish: " << breed << ", " << color << ", Food type: " << foodType << std::endl;
}

void Fish::setFoodType(const std::string& foodType) {
    this->foodType = foodType;
}

std::string Fish::getFoodType() const {
    return foodType;
}
