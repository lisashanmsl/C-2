#ifndef DEMON_H
#define DEMON_H
#include"Creature.h"
using namespace std;

class Demon :public Creature
{
public:
    Demon();
    Demon(int type, int strength, int hitpoints);

    virtual int getDamage()const override;
};
#endif#pragma once
