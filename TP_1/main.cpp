#include "Keeper.h"
#include "Animal.h"
#include <iostream>

int main() {
    Keeper keeper;
    int choice;
    std::string breed, color, dietType, food, habitat, ownerName, nickname;
    int index;

    while (true) {
        std::cout << "1. Add Fish\n2. Add Bird\n3. Add Cat\n4. Display Animals\n5. Save to File\n6. Load from File\n7. Remove Animal\n8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter breed: ";
                std::cin >> breed;
                std::cout << "Enter color: ";
                std::cin >> color;
                std::cout << "Enter diet type: ";
                std::cin >> dietType;
                keeper.addAnimal(new Fish(breed, color, dietType));
                break;
            case 2:
                std::cout << "Enter breed: ";
                std::cin >> breed;
                std::cout << "Enter color: ";
                std::cin >> color;
                std::cout << "Enter food: ";
                std::cin >> food;
                std::cout << "Enter habitat: ";
                std::cin >> habitat;
                keeper.addAnimal(new Bird(breed, color, food, habitat));
                break;
            case 3:
                std::cout << "Enter breed: ";
                std::cin >> breed;
                std::cout << "Enter color: ";
                std::cin >> color;
                std::cout << "Enter owner name: ";
                std::cin >> ownerName;
                std::cout << "Enter nickname: ";
                std::cin >> nickname;
                keeper.addAnimal(new Cat(breed, color, ownerName, nickname));
                break;
            case 4:
                keeper.displayAnimals();
                break;
            case 5:
                keeper.saveToFile("animals.txt");
                break;
            case 6:
                keeper.loadFromFile("animals.txt");
                break;
            case 7:
                keeper.removeAnimal();
                break;
            case 8:
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}
