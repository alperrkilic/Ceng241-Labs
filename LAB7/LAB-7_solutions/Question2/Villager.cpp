#include "Villager.h"

Villager::Villager() : health{20}, attackPower{0}
{
}

Villager::~Villager()
{
}

int Villager::attack(Villager &villager_person)
{
    return 0; // villager can't attack
}

int Villager::getHealth(void)
{
    return this->health;
}

void Villager::setHealth(int health)
{
    this->health = health;
}