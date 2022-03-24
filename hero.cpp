//
// Created by Alexander Huber on 24.03.22.
//

#include "hero.h"

void Hero::attack(Character *enemy)
{
    //Berechnung einer zufälligen Zahl zwischen 15 und 25
    int rndNumber = 15 + std::rand() % (25 - 15 + 1);

    //Berechnung des Schadens
    //Bei Hero ist die Vorgabe "damage = rand(15,25) - armor"
    //Wert von "armor" bezieht sich auf den Gegner
    int damage = rndNumber - enemy->getArmor();
    enemy->setHealth(enemy->getHealth() - damage);

    std::cout << this->getName() << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte." << std::endl;
}

int Hero::addEquipmentItem(const Item& item)
{
    for(int i = 0; i < MAX_EQUIPMENT_SIZE; i++)
    {
        if(!this->hero_gear[i].isIsValid())
        {
            this->hero_gear[i].setName(item.getName());
            this->hero_gear[i].setValue(item.getValue());
            //this->hero_gear[i].isValid(true);
            this->hero_gear[i].isIsValid();

            //Bei erfolgreicher Platzierung soll der Index des Items ausgegeben werden
            return i;
        }
    }
    //Falls alle Plätze belegt sind oder der Platz falsch initialisiert ist, soll der Wert "-1" ausgegeben werden
    return -1;
}

Item Hero::removeEquipmentItem(int slot)
{
    if(this->hero_gear[slot].isIsValid())
    {
        this->hero_gear[slot].setIsValid(false);
        std::cout << "Das Item " << this->hero_gear[slot].getName() << " wurde aus dem Invenatr von " << this->getName() << " entfernt." << std::endl;
        return this->hero_gear[slot];
    } else
    {
        //Falls alle Plätze belegt oder der Slot fehlerhaft initialisiert sein,
        //wird der Default-Konstruktor verwendet und das Item "Default-Item" mit isValid "false" ausgegeben
        return Item();
    }
}

void Hero::sellItem(int index)
{
    /*
     * Erster Ansatz, aber fehlerhaft
    //Pointer auf das Item am angegebenen Index
    Item *sellItem = this->getInventory(index);

    //Prüfung, ob das gewählte Item mit "true" initialisiert wurde
    //falls ja, wird der Wert auf "false" gesetzt
    if(sellItem->isIsValid())
    if(this->getInventory(index)->isIsValid())
    {
        sellItem->setIsValid(false);

        //Berechnung des neuen Guthabens
        //setGold/ neuer Wert = getGold/ alter Wert + Wert des Items
        this->setGold(this->getGold() + sellItem->getValue());
    }
    */

    //Alternative Umsetzung
    if(this->getInventory(index)->isIsValid())
    {
        this->getInventory(index)->setIsValid(false);
        this->setGold(this->getGold() + this->getInventory(index)->getValue());
        //this->setGold(this->getInventory(index)->getValue());
    }

    //Ausgabe einer Bestätigung über das Terminal
    std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für " << this->getInventory(index)->getValue() << " verkauft. " << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
}

enumType& Hero::getType()
{
    return this->typ;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
    std::cout << "Hero " << h.getName() << " mit " << h.getHealth() << " Lebenspunkten, " << h.getArmor() << " Rüstungspunkte, " << h.getMR() << " Magieresistenz und " << h.getGold() << " Gold." << std::endl;
    return out;
}