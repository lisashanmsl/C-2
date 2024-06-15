#include"Balrog.h"
#include<string>
#include<cstdlib>
using namespace std;

Balrog::Balrog() :Demon() {}

Balrog::Balrog(int type, int strength, int hitpoints) :Demon(type, strength, hitpoints) {}

string Balrog::getSpecies()const
{
    return"Balrog";
}

int Balrog::getDamage()const
{
    int damage1 = Demon::getDamage();
    int damage2 = (rand() % getStrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    return damage1 + damage2;
}