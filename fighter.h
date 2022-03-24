//
// Created by Alexander Huber on 24.03.22.
//

#ifndef EXERCISE_3_FIGHTER_H
#define EXERCISE_3_FIGHTER_H

#include <string.h>

#include "npc.h"

class Fighter : public NPC
{
private:
    int strength;
    enumType typ;

protected:

public:
    //Konstruktoren der Class "Fighter"
    /*
    //Default
    Fighter() : char_name("Default-Fighter")
    {
        std::cout << "Fighter::Constructor: " << char_name << std::endl;
    }
    */

    //Individueller Konstruktor
    Fighter(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr, int strength)
            : NPC(char_name, char_health, char_gold, char_armor, char_mr), strength(strength), typ(typeFighter)
    {
        std::cout << "Fighter::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Fighter()
    {
        std::cout << "Fighter " << this->getName() << " verlässt das Abenteuer und ärgert andere Helden*Innen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    virtual enumType &getType() override;

    //----------------------------- Getter & Setter -----------------------------
    int getStrength() const;
    void setStrength(int newStrength);
};

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Fighter& f);

#endif //EXERCISE_3_FIGHTER_H
