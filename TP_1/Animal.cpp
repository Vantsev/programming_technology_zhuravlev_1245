#include "Animal.h"

// Animal class implementation
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

// Fish class implementation
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

// Bird class implementation
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

// Cat class implementation
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
