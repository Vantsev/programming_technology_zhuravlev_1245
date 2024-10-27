#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal(), ownerName("Unknown"), nickname("Unknown") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname)
        : Animal(breed, color), ownerName(ownerName), nickname(nickname) {
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
        : Animal(other), ownerName(other.ownerName), nickname(other.nickname) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::display() const {
    std::cout << "Cat - Breed: " << breed << ", Color: " << color << ", Owner Name: " << ownerName << ", Nickname: " << nickname << std::endl;
}

void Cat::setData(const std::string& breed, const std::string& color) {
    this->breed = breed;
    this->color = color;
}

std::string Cat::getOwnerName() const {
    return ownerName;
}

void Cat::setOwnerName(const std::string& ownerName) {
    this->ownerName = ownerName;
}

std::string Cat::getNickname() const {
    return nickname;
}

void Cat::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}
