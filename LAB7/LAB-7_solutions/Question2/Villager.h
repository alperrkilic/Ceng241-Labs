#ifndef VILLAGER
#define VILLAGER
class Villager
{
protected:
    int health;
    int attackPower;

public:
    Villager();
    ~Villager();
    int attack(Villager &villager_person);
    int getHealth(void);
    void setHealth(int health);
};

#endif