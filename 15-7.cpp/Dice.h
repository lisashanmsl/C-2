//define base class
#ifndef DICE_H
#define DICE_H
#include<iostream>
using namespace std;

class Dice
{
public:
	Dice();								//default constructor
	Dice(int numSides);					//constructor
	virtual int rollDice()const;		//virtual function override in derived class

protected:
	int numSides;						//number of dice side
};
int rollTwoDice(const Dice& dice1, const Dice& dice2);

#endif
