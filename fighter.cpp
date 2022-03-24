//
// Created by Alexander Huber on 24.03.22.
//

#include "fighter.h"

#include <iostream>

//----------------------------- Objektfunktionen -----------------------------
void Fighter::attack(Character *enemy)
{
    //Berechnung einer zufälligen Zahl zwischen 15 und 25
    int rndNumber = 5 + std::rand() % (10 - 5 + 1);

    //Berechnung des Schadens
    //Bei Fighter ist die Vorgabe "damage = rand(5, 10) + strength - armor"
    //Wert von Strenght bezieht sich auf den ausführeden Character/ Fighter
    //Wert von "armor" bezieht sich auf den Gegner
    int damage = (rndNumber + this->getStrength()) - enemy->getArmor();
    enemy->setHealth(enemy->getHealth() - damage);

    std::cout << this->getName() << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte." << std::endl;
}

enumType& Fighter::getType()
{
    return this->typ;
}

//----------------------------- Getter & Setter -----------------------------
int Fighter::getStrength() const
{
    return this->strength;
}

void Fighter::setStrength(int newStrength)
{
    this->strength = newStrength;
}

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Fighter& f)
{
    std::cout << "Fighter " << f.getName() << " mit " << f.getHealth() << " Lebenspunkten, " << f.getArmor() << " Rüstungspunkte, " << f.getMR() << " Magieresistenz und " << f.getStrength() <<
              " Muskelkraft sowie " << f.getGold() << " Gold." << std::endl;
    return out;
}