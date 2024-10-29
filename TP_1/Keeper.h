#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include <vector>
#include <string>

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addAnimal(Animal* animal);
    void removeAnimal();
    void displayAnimals() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Animal*> animals;
};

#endif // KEEPER_H
