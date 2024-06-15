#ifndef BALROG_H
#define BALROG_H
#include"Demon.h"
#include<string>
using namespace std;

class Balrog :public Demon
{
public:
    Balrog();
    Balrog(int type, int strength, int hitpoints);

    virtual string getSpecies()const override;
    virtual int getDamage()const override;
};
#endif      #pragma once
