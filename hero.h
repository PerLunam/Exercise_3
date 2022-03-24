//
// Created by Alexander Huber on 24.03.22.
//

#ifndef EXERCISE_3_HERO_H
#define EXERCISE_3_HERO_H

#include <string>

#include "character.h"

#define MAX_EQUIPMENT_SIZE 2

class Hero : public Character
{
private:
    Item hero_gear[MAX_EQUIPMENT_SIZE];
    enumType typ;

protected:

public:
    //Konstruktoren der Class "Hero"
    /*
    //Default
    Hero() : char_name("Default-Hero")
    {
        std::cout << "Hero::Constructor: " << char_name << std::endl;
    }
    */

    //Individueller Konstruktor
    Hero(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr)
            : Character(char_name, char_health, char_gold, char_armor, char_mr), typ(typeHero)
    {
        //Initialisierung der Ausrüstung mit dem Default-Konstruktor aka "Default-Item" und "false"
        for(int i = 0; i < MAX_EQUIPMENT_SIZE; i++)
        {
            this->hero_gear[i] = Item();
        }

        std::cout << "Hero::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Hero()
    {
        std::cout << "Hero " << this->getName() << " verabschiedet sich und geht voller Stolz der untergehenden Sonne entgegen." << std::endl;
        //std::cout << this->getType() << " " << this->getName() << " verabschiedet sich und geht voller Stolz der untergehenden Sonne entgegen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);

    void sellItem(int index);

    virtual enumType& getType() override;

    //----------------------------- Getter & Setter -----------------------------
    //Werden von der Elternklasse "Character" übernommen
};

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Hero& h);

#endif //EXERCISE_3_HERO_H
