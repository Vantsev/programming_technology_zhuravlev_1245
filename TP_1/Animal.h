#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    Animal(const Animal& other);
    virtual ~Animal();

    virtual void display() const = 0;
    virtual void setData(const std::string& breed, const std::string& color) = 0;

    std::string getBreed() const;
    std::string getColor() const;

protected:
    std::string breed;
    std::string color;
};

#endif // ANIMAL_H
