#include "Keeper.h"
#include "Fish.h"
#include <iostream>

void showMenu() {
    std::cout << "1. Add Fish" << std::endl;
    std::cout << "2. Remove Animal" << std::endl;
    std::cout << "3. Show all Animals" << std::endl;
    std::cout << "4. Save to file" << std::endl;
    std::cout << "5. Load from file" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main() {
    Keeper keeper;
    int choice;
    do {
        showMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string breed, color, foodType;
                std::cout << "Enter breed: ";
                std::cin >> breed;
                std::cout << "Enter color: ";
                std::cin >> color;
                std::cout << "Enter food type: ";
                std::cin >> foodType;
                Fish* fish = new Fish(breed, color, foodType);
                keeper.addAnimal(fish);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter the index of the animal to remove: ";
                std::cin >> index;
                try {
                    keeper.removeAnimal(index);
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 3:
                keeper.printAnimals();
                break;
            case 4:
                keeper.saveToFile("animals.dat");
                break;
            case 5:
                keeper.loadFromFile("animals.dat");
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
