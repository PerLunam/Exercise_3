//
// Created by Alexander Huber on 24.03.22.
//

#include "item.h"

const std::string &Item::getName() const
{
    return this->item_name;
}

void Item::setName(const std::string &newName)
{
    this->item_name = newName;
}

int Item::getValue() const
{
    return this->item_value;
}

void Item::setValue(int newValue)
{
    this->item_value = newValue;
}

bool Item::isIsValid() const
{
    return this->isValid;
}

void Item::setIsValid(bool newIsValid)
{
    this->isValid = newIsValid;
}

/*
std::ostream& operator<<(std::ostream& out, const Item& i)
{
    std::cout << i.getName() << " mit einem Wert von " << i.getValue() << std::endl;
    return out;
}
*/