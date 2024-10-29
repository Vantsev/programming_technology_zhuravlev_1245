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
    void displayAnimals() const; //const не влияет на Keeper
    void displayAnimalsByType(const std::string& type) const; //const не влияет на Keeper
    void removeAnimalByType(const std::string& type, int index);
    void saveToFile(const std::string& filename) const; //const не влияет на Keeper
    void loadFromFile(const std::string& filename);

private:
    std::vector<Animal*> animals; //динамический массив используется для хранения указателей на объекты класса Animal
    // и его производных классов (Fish, Bird, Cat).
};

#endif // KEEPER_H
