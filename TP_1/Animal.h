#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

// Базовый класс Animal
class Animal {
public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    Animal(const Animal& other);
    virtual ~Animal();

    // Виртуальный метод для отображения информации о животном
    virtual void display() const = 0;
    // Виртуальный метод для установки породы и цвета животного
    virtual void setData(const std::string& breed, const std::string& color) = 0;

    // Методы для получения породы и цвета животного
    std::string getBreed() const;
    std::string getColor() const;

protected:
    std::string breed;
    std::string color;
};

// Класс Fish, наследуемый от Animal
class Fish : public Animal {
public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& dietType);
    Fish(const Fish& other);
    ~Fish();

    // Переопределенный метод для отображения информации о рыбе
    void display() const override;
    // Переопределенный метод для установки породы и цвета рыбы
    void setData(const std::string& breed, const std::string& color) override;

    // Методы для получения и установки типа питания рыбы
    std::string getDietType() const;
    void setDietType(const std::string& dietType);

private:
    std::string dietType;
};

// Класс Bird, наследуемый от Animal
class Bird : public Animal {
public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird();

    // Переопределенный метод для отображения информации о птице
    void display() const override;
    // Переопределенный метод для установки породы и цвета птицы
    void setData(const std::string& breed, const std::string& color) override;

    // Методы для получения и установки еды и места обитания птицы
    std::string getFood() const;
    void setFood(const std::string& food);

    std::string getHabitat() const;
    void setHabitat(const std::string& habitat);

private:
    std::string food;
    std::string habitat;
};

// Класс Cat, наследуемый от Animal
class Cat : public Animal {
public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat();

    // Переопределенный метод для отображения информации о кошке
    void display() const override;
    // Переопределенный метод для установки породы и цвета кошки
    void setData(const std::string& breed, const std::string& color) override;

    // Методы для получения и установки имени владельца и клички кошки
    std::string getOwnerName() const;
    void setOwnerName(const std::string& ownerName);

    std::string getNickname() const;
    void setNickname(const std::string& nickname);

private:
    std::string ownerName;
    std::string nickname;
};

#endif // ANIMAL_H
