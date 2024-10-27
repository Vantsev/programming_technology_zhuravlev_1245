#ifndef CAT_H
#define CAT_H

#include "Animal.h"

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

#endif // CAT_H
