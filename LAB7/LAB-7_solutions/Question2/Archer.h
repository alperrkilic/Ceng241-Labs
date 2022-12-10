#ifndef ARCHER
#define ARCHER
#include "Villager.h"

class Archer : public Villager
{
private:
    int nrOfArrows;

public:
    Archer();
    ~Archer();
    int attack(Villager &target_villager);
    int attack(Archer &target_archer);
    int get_nrOfArrows(void);
};

#endif