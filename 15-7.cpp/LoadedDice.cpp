#include"LoadedDice.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

LoadedDice::LoadedDice() :Dice(){}

LoadedDice::LoadedDice(int numSides) :Dice(numSides){}

int LoadedDice::rollDice()const
{
	if (rand() % 2 == 0) {				//50% chance return numSides
		return numSides;
	}
	else return (Dice::rollDice());		//else 50% return what Dice class's rollDice function return
}