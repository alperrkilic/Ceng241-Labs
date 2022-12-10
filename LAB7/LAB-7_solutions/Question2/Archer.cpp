#include "Archer.h"
#include <stdlib.h>
#include <time.h>

Archer::Archer() : Villager{}, nrOfArrows{5}
{
    health = 60;
    attackPower = 40;
}

Archer::~Archer()
{
}

int Archer::attack(Villager &target_villager)
{
    srand(time(NULL));

    if (target_villager.getHealth() <= 0)
    {
        return -1;
    }
    else if (nrOfArrows == 0)
    {
        return -2;
    }
    else
    {
        // Temp variables
        int damage;
        int health;

        damage = 0 + (rand() % 41); // Generate damage between 0 and 40 (attack_power)
        nrOfArrows--;
        return damage;
    }
}

int Archer::attack(Archer &target_archer)
{

    srand(time(NULL));

    if (target_archer.getHealth() <= 0)
    {
        return -1; // target is already dead.
    }
    else if (nrOfArrows == 0)
    {
        return -2; // there is no arrows attacker cannot attack.
    }
    else
    {
        // Temp variables
        int damage;
        int health;

        damage = 0 + (rand() % 41); // Generate damage between 10 and 25
        nrOfArrows--;               //  attacker archer's number of arrow should be decreased by one.
        return damage;
    }
}

int Archer::get_nrOfArrows(void)
{
    return this->nrOfArrows;
}