#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

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

class Cat : public Animal {
public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat();

    void display() const override;
    void setData(const std::string& breed, const std::string& color) override;

    std::string getOwnerName() const;
    void setOwnerName(const std::string& ownerName);

    std::string getNickname() const;
    void setNickname(const std::string& nickname);

private:
    std::string ownerName;
    std::string nickname;
};

#endif // ANIMAL_H
