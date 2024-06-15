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

int main(void)
{
    // Initialize the random number generator
    srand(time(NULL));

    // Create objects for different types of creatures and initialize their attributes
    Human human(0, 20, 30);        // Human, type 0, strength 20, hit points 30
    Elf elf(3, 15, 25);            // Elf, type 3, strength 15, hit points 25
    Cyberdemon cyber(1, 30, 40);   // Cyberdemon, type 1, strength 30, hit points 40
    Balrog balrog(2, 40, 50);      // Balrog, type 2, strength 40, hit points 50

    // Output the species, strength, and hit points, and calculate the damage for each creature
    cout << human.getSpecies() << " with strength " << human.getStrength() << " and hit points " << human.getHitpoints() << endl;
    cout << "Damage: " << human.getDamage() << endl << endl;

    cout << elf.getSpecies() << " with strength " << elf.getStrength() << " and hit points " << elf.getHitpoints() << endl;
    cout << "Damage: " << elf.getDamage() << endl << endl;

    cout << cyber.getSpecies() << " with strength " << cyber.getStrength() << " and hit points " << cyber.getHitpoints() << endl;
    cout << "Damage: " << cyber.getDamage() << endl << endl;

    cout << balrog.getSpecies() << " with strength " << balrog.getStrength() << " and hit points " << balrog.getHitpoints() << endl;
    cout << "Damage: " << balrog.getDamage() << endl << endl;

    // Pause the system (for Windows; remove if not using Windows)
    system("pause");
    return 0;
}
