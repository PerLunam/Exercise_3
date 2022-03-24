//
// Created by Alexander Huber on 24.03.22.
//

#ifndef EXERCISE_3_ITEM_H
#define EXERCISE_3_ITEM_H

#include <iostream>
#include <string>

class Item
{
    private:
    std::string item_name;
    int item_value;
    bool isValid;

    protected:

    public:
    //Konstruktoren der Class "Character"
    //Default
    Item() : item_name("Default-Item"), item_value(0), isValid(false)
    {
        //std::cout << "Calling Item::Default-Constructor" << std::endl;
        //std::cout << "Konstruktor: " << item_name << std::endl;
    }

    //Individueller Konstruktor
    Item(const std::string &name, int value)
        : item_name(name), item_value(value), isValid(true)
        {
            std::cout << "Item::Constructor : " << item_name << std::endl;
        }

    //Destruktor
    ~Item()
    {
        //std::cout << "Destruktor: " << item_name << std::endl;
    }

    //----------------------------- Getter & Setter -----------------------------
    const std::string &getName() const;
    void setName(const std::string &newName);

    int getValue() const;
    void setValue(int newValue);

    bool isIsValid() const;
    void setIsValid(bool newIsValid);
};

//Operatorenüberladung des Operators "<<"
//std::ostream& operator<<(std::ostream& out, const Item& i);

#endif //EXERCISE_3_ITEM_H
