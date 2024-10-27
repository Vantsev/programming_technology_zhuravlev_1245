#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird();

    void display() const override;
    void setData(const std::string& breed, const std::string& color) override;

    std::string getFood() const;
    void setFood(const std::string& food);

    std::string getHabitat() const;
    void setHabitat(const std::string& habitat);

private:
    std::string food;
    std::string habitat;
};

#endif // BIRD_H
