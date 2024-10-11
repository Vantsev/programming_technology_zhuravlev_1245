#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
private:
    std::string foodType;

public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& foodType);
    ~Fish();

    void printInfo() const override;

    void setFoodType(const std::string& foodType);
    std::string getFoodType() const;
};

#endif
