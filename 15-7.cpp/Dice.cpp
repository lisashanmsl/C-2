#include"Dice.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Dice::Dice()						//default six side of dice
{
	numSides = 6;
	srand(time(NULL));				//set random seed
}
Dice::Dice(int numSides)	
{
	this->numSides = numSides;		//set numSides
	srand(time(NULL));
}
int Dice::rollDice()const
{
	return(rand() % numSides) + 1;	//return number between 1 to numSides
}
int rollTwoDice(const Dice& dice1, const Dice& dice2)
{
	//return the sum of point of two dice after rolled
	return(dice1.rollDice() + dice2.rollDice());
}