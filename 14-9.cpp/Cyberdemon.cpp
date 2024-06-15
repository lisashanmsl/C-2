#include"Cyberdemon.h"
#include<string>
using namespace std;

Cyberdemon::Cyberdemon() :Demon() {}

Cyberdemon::Cyberdemon(int type, int strength, int hitpoints) :Demon(type, strength, hitpoints) {}

string Cyberdemon::getSpecies()const
{
    return"Cyberdemon";
}