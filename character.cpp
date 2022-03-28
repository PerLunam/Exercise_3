//
// Created by Alexander Huber on 24.03.22.
//

#include "character.h"

#include <iostream>

//----------------------------- Objektfunktionen -----------------------------
bool Character::fight(Character *enemy)
{
    std::cout << enemy->getName() << " fordert " << this->getName() << " zu einem Kampf um Ruhm und Ehre heraus." << std::endl;

    //Lösung mithilfe einer Do-While-Loop
    do
    {
        this->attack(enemy);
        enemy->attack(this);
    } while(this->getHealth() > 0 && enemy->getHealth() > 0);

    std::cout << enemy->getName() << " fiel in Ohnmacht! " << this->getName() << " hat noch " << this->getHealth() << " Lebenspunkte." << std::endl;

    //Grafische Trennung der Inhalte
    std::cout << "------------------------------" << std::endl;

    //Falls Hero gewinnt, wird hier "true" zurückgegeben
    return this->getHealth() > 0;
}

int Character::addInventarItem(const Item &item)
{
    for(int i = 0; i < MAX_INVENTORY_SIZE; i++)
    {
        if(!this->inventory[i].isIsValid())
        {
            this->inventory[i].setName(item.getName());
            this->inventory[i].setValue(item.getValue());
            this->inventory[i].setIsValid(true);

            //Bei erfolgreicher Platzierung soll der Index des Items ausgegeben werden
            return i;
        }
    }
    //Falls alle Plätze belegt sind oder der Platz falsch initialisiert ist, soll der Wert "-1" ausgegeben werden
    return -1;
}

Item Character::removeInventarItem(int slot)
{
    if(this->inventory[slot].isIsValid())
    {
        this->inventory[slot].setIsValid(false);
        std::cout << "Item  \"" << this->inventory[slot].getName() << "\" wurde aus dem Inventar von " << this->getName() << " entfernt." << std::endl;
        return this->inventory[slot];
    } else
    {
        //Falls alle Plätze belegt oder der Slot fehlerhaft initialisiert sein,
        //wird der Default-Konstruktor verwendet und das Item "Default-Item" mit isValid "false" ausgegeben
        return Item();
    }
}

Item Character::retrieveRandomLoot(Character *enemy)
{
    //Initialisierung eines Counters, welcher als Zahlenbasis für die Zufallszahlgenerierung dient
    int counter = -1;

    //Für jedes ".isIsvalid == true" wird der counter um 1 erhöht
    //Max. Wert = 9, da MAX_INVENTORY_SIZE als Array[10] also mit Index von 0 bis 9 definiert ist
    for(int i = 0; i < MAX_INVENTORY_SIZE; i++)
    {
        if(enemy->inventory[i].isIsValid())
        {
            counter++;
        }
    }

    //Zufällige Zahl wird generiert und dient als Kriterium für die Auswahl des entsprechenden Item-Index
    int rndNumber = rand() % (counter);
    //std::cout << "Zufallszahl = " << rndNumber << std::endl;

    if(enemy->inventory[rndNumber].isIsValid())
    {
        //falls der Index korrekt initialisiert ist (isValid = "true"), soll das Item aus dem Inventar des Gegners entfernt ("removeInventarItem")
        //und in das Inventar des Helden/ der Heldin beigefügt werden ("addInventarItem")

        //Erster Versuch der Umsetzung, aber mit Fehler
        //this->addInventarItem(&enemy->removeInventarItem(rndNumber));

        //Zweiter Versuch der Umsetzung
        //Deklaration einer Variablen für das Item an Index "rndNumber"
        Item lootItem = enemy->inventory[rndNumber];

        //Item wird aus dem Inventar des Gegners entfernt
        enemy->removeInventarItem(rndNumber);

        //Das entsprechende Item wird dem Inventar des Helden/ der Heldin beigefügt
        this->addInventarItem(lootItem);

        //std::cout << "Des einen Glück, des anderen Leid. " << this->getName() << " hat sich \"" << enemy->getInventory(rndNumber)->getName() << "\" redlich verdient." << std::endl;
        std::cout << "Des einen Glück, des anderen Leid. " << this->getName() << " hat sich \"" << lootItem.getName() << "\" redlich verdient." << std::endl;

        //Grafische Trennung der Inhalte
        std::cout << "------------------------------" << std::endl;

        return lootItem;
    } else
    {
        //Falls alle Plätze belegt oder der Slot fehlerhaft initialisiert sein,
        //wird der Default-Konstruktor verwendet und das Item "Default-Item" mit isValid "false" ausgegeben
        std::cout << "Kein Platz vorhanden. " << enemy->getInventory(rndNumber)->getName() << " bleibt " << this->getName() << " leider verwehrt." << std::endl;

        //Grafische Trennung der Inhalte
        std::cout << "------------------------------" << std::endl;

        return Item();
    }
}

//----------------------------- Getter & Setter -----------------------------
const std::string& Character::getName() const
{
    return this->char_name;
}

void Character::setName(const std::string& newName)
{
    this->char_name = newName;
}

int Character::getHealth() const
{
    return this->char_health;
}

void Character::setHealth(int newHealth)
{
    this->char_health = newHealth;
}

int Character::getGold() const
{
    return this->char_gold;
}

void Character::setGold(int newGold)
{
    this->char_gold = newGold;
}

int Character::getArmor() const
{
    return this->char_armor;
}

void Character::setArmor(int newArmor)
{
    this->char_armor = newArmor;
}

int Character::getMR() const
{
    return this->char_mr;
}

void Character::setMR(int newMR)
{
    this->char_mr = newMR;
}

Item *Character::getInventory(int index)
{
    Item &item = this->inventory[index];
    return &item;
}

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Character& c)
{
    std::cout << c.getName() << " mit " << c.getHealth() << " Lebenspunkten, " << c.getArmor() << " Rüstungspunkte, " << c.getMR() << " Magieresistenz und " << c.getGold() << " Gold." << std::endl;
    return out;
}
