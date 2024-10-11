#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include <fstream>

class Keeper {
private:
    Animal** animals;
    int size;

public:
    Keeper();
    ~Keeper();

    void addAnimal(Animal* animal);
    void removeAnimal(int index);
    void printAnimals() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
