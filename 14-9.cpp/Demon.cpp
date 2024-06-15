#include"Demon.h"
#include<cstdlib>
using namespace std;

Demon::Demon() :Creature() {}

Demon::Demon(int type, int strength, int hitpoints) :Creature(type, strength, hitpoints) {}

int Demon::getDamage()const
{
    int damage = Creature::getDamage();
    if ((rand() % 100) < 5) {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }
    return damage;
}