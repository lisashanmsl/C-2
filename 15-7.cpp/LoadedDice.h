//define derived class
#ifndef LOADEDDICE_H
#define LOADEDDICE_H
#include"Dice.h"
#include<iostream>
using namespace std;

class LoadedDice :public Dice			//dervied from Dice
{
public:
	LoadedDice();						//default constructor
	LoadedDice(int numSides);			//constructor
	int rollDice()const override;		//override virtual function in base class
};
#endif