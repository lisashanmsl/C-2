#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include"Demon.h"
#include<string>
using namespace std;

class Cyberdemon :public Demon
{
public:
    Cyberdemon();
    Cyberdemon(int type, int strength, int hitpoints);

    virtual string getSpecies()const override;
};
#endif#pragma once
