#include"Human.h"
#include<string>
using namespace std;

Human::Human() :Creature() {}

Human::Human(int type, int strength, int hitpoints) :Creature(type, strength, hitpoints) {}

string Human::getSpecies()const
{
    return "Human";
}