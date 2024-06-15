#ifndef ELF_H
#define ELF_H
#include"Creature.h"
#include<string>
using namespace std;

class Elf :public Creature
{
public:
    Elf();
    Elf(int type, int strength, int hitpoints);

    virtual int getDamage()const override;
    virtual string getSpecies()const override;
};
#endif#pragma once
