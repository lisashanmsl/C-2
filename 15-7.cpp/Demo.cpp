#include"Dice.h"
#include"LoadedDice.h"
#include<iostream>
using namespace std;

int main(void) 
{
	Dice dice1(4), dice2(10);						

	cout << "Test Dice object." << endl;
	cout << "Roll dice1 and dice2 ten time and print the sum. " << endl << endl;
	for (int i = 1; i <= 10; i++) {
		cout << "Roll " << i << ": " << rollTwoDice(dice1, dice2) << endl;
	}cout << endl;


	LoadedDice loadDice1(4), loadDice2(10);

	//polymorphism: using LoadedDice's rollDice function 
	//rollDice is a virtual function
	cout << "Test LoadedDice object." << endl;
	cout << "Roll dice1 and dice2 ten time and print the sum. " << endl << endl;
	for (int i = 1; i <= 10; i++) {
		cout << "Roll " << i << ": " << rollTwoDice(loadDice1, loadDice2) << endl;
	}

	return 0;
}