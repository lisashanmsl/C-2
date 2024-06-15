#include"Creature.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

Creature::Creature() :type(0), strength(10), hitpoints(10) {}

Creature::Creature(int type, int strength, int hitpoints)
{
    this->type = type;
    this->strength = strength;
    this->hitpoints = hitpoints;
}

int Creature::getStrength() const { return strength; }

int Creature::getHitpoints() const { return hitpoints; }

void Creature::setStrength(int newStrength) { strength = newStrength; }

void Creature::setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

string Creature::getSpecies()const
{
    return "Unknown";
}

int Creature::getDamage()const
{
    int damage = (rand() % strength) + 1;

    cout << getSpecies() << " attack " << damage << " points." << endl;
    return damage;
}
