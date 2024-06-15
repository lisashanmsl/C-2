#ifndef HUMAN_H
#define HUMAN_H
#include"Creature.h"
#include<string>
using namespace std;

class Human :public Creature
{
public:
    Human();
    Human(int type, int strength, int hitpoints);

    virtual string getSpecies()const override;
};
#endif#pragma once
