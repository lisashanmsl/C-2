#include"Elf.h"
#include<string>
#include<cstdlib>
using namespace std;

Elf::Elf() :Creature() {}

Elf::Elf(int type, int strength, int hitpoints) :Creature(type, strength, hitpoints) {}

string Elf::getSpecies()const
{
    return"Elf";
}

int Elf::getDamage()const
{
    int damage = Creature::getDamage();
    if (rand() % 10 == 0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage = damage * 2;
    }
    return damage;
}