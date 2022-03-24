//
// Created by Alexander Huber on 24.03.22.
//

#ifndef EXERCISE_3_SORCERER_H
#define EXERCISE_3_SORCERER_H

#include <string.h>

#include "npc.h"

class Sorcerer : public NPC
{
private:
    int magicPower;
    enumType typ;

protected:

public:
    //Konstruktoren der Class "Sorcerer"
    /*
    //Default
    Sorcerer() : char_name("Default-Sorcerer")
    {
        std::cout << "Sorcerer::Constructor: " << char_name << std::endl;
    }
    */

    //Individueller Konstruktor
    Sorcerer(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr, int magicPower)
            : NPC(char_name, char_health, char_gold, char_armor, char_mr), magicPower(magicPower), typ(typeSorcerer)
    {
        std::cout << "Sorcerer::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Sorcerer()
    {
        std::cout << "Sorcerer " << this->getName() << " verlässt das Abenteuer und ärgert andere Helden*Innen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    virtual enumType &getType() override;

    //----------------------------- Getter & Setter -----------------------------
    int getMagicPower() const;
    void setMagicPower(int newMagicPower);
};

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Sorcerer& s);

#endif //EXERCISE_3_SORCERER_H
