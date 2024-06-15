// Include the header files for each creature class
#include "Creature.h"
#include "Human.h"
#include "Demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include "Elf.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void battleArena(Creature& creature1, Creature& creature2);

int main(void)
{
    // Initialize the random number generator
    srand(time(NULL));

    // Create objects for different types of creatures and initialize their attributes
    Human human;
    Elf elf;
    Cyberdemon cyber;
    Balrog balrog;

    //�]�w�ͩR�ȩM�����O
    human.setStrength(20);
    human.setHitpoints(60);

    elf.setStrength(15);
    elf.setHitpoints(50);

    cyber.setStrength(30);
    cyber.setHitpoints(30);

    balrog.setStrength(25);
    balrog.setHitpoints(25);

    cout << "Testing individual battles:" << endl;
    battleArena(human, cyber);
    battleArena(elf, balrog);

    system("pause");
    return 0;
}
void battleArena(Creature& creature1, Creature& creature2) {

    //���褬�ۧ������쳣�S��
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        
        //��l������ˮ`
        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();
        
        //�]�w�Q�������᪺��q
        creature2.setHitpoints(creature2.getHitpoints() - damage1);
        creature1.setHitpoints(creature1.getHitpoints() - damage2);

        if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
            cout << "The battle is a tie!" << endl;
        }
        else if (creature1.getHitpoints() <= 0) {
            cout << creature2.getSpecies() << " wins!" << endl;
        }
        else if (creature2.getHitpoints() <= 0) {
            cout << creature1.getSpecies() << " wins!" << endl;
        }
    }
}