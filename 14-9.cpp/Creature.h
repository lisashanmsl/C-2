#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<string>
using namespace std;

class Creature
{
public:
    Creature();
    Creature(int type, int strength, int hitpoints);

    int getStrength() const;
    int getHitpoints() const;
    void setStrength(int newStrength);
    void setHitpoints(int newHitpoints);

    virtual int getDamage()const;
    virtual string getSpecies()const;

private:
    int type;           //0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength;       //how much damage we can inflict 
    int hitpoints;      //how much damage we can sustain
};
#endif