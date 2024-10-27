#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& dietType);
    Fish(const Fish& other);
    ~Fish();

    void display() const override;
    void setData(const std::string& breed, const std::string& color) override;

    std::string getDietType() const;
    void setDietType(const std::string& dietType);

private:
    std::string dietType;
};

#endif // FISH_H
