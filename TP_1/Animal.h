#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string breed;
    std::string color;

public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    virtual ~Animal();

    virtual void printInfo() const = 0;

    void setBreed(const std::string& breed);
    std::string getBreed() const;

    void setColor(const std::string& color);
    std::string getColor() const;
};

#endif
