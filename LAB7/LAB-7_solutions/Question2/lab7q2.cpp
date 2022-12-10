#include <iostream>
#include <ctype.h>
#include <string>
#include "Archer.h"
#include "Villager.h"

using namespace std;

// Functions
void menu(void);
void attacker_choice(Archer *attacker_archer, Archer *defender_archer, Villager *attacker_villager, Villager *defender_villager);
void defender_choice(Archer *attacker_archer, Archer *defender_archer, Villager *attacker_villager, Villager *defender_villager);
void lower_function(string &char_type);

// Designing part:
// two teams each has 3 archer 3 villager
// fighting for their villages

int main(void)
{
    menu();

    cout << "Goodbye!" << endl;

    return 0;
}

void menu(void)
{
    int choice{0};
    Archer attacker_archer[3];
    Villager attacker_villager[3];

    Archer defender_archer[3];
    Villager defender_villager[3];

    cout << "\nWelcome to the War of Villages" << endl;
    cout << "1-Attacker" << endl;
    cout << "2-Defender" << endl;
    cout << "Choose a Team: ";
    cin >> choice;

    while (choice != 1 && choice != 2)
    {
        cout << "You have entered a wrong choice..." << endl;
        cout << "Please choose 1 or 2: ";
        cin >> choice;
    }

    cout << endl
         << endl;

    if (choice == 1)
    {
        attacker_choice(attacker_archer, defender_archer, attacker_villager, defender_villager);
    }
    else if (choice == 2)
    {
        defender_choice(attacker_archer, defender_archer, attacker_villager, defender_villager);
    }
}

void attacker_choice(Archer *attacker_archer, Archer *defender_archer, Villager *attacker_villager, Villager *defender_villager)
{
    cout << "Rules: " << endl;
    cout << "\nYou have choosen the attacker team, attack by ATTACK command." << endl;
    cout << "\nSample attack command: Attacker_Archer 1 ATTACK Defender_Villager 3" << endl;
    cout << "\nAttacker villagers cannot attack, they produce food for the attacker archers." << endl;

    int command_num{0};
    string command_string{};

    string type1;
    int type1_num{};
    string type2;
    int type2_num{};

    do
    {
        cout << "Enter command #" << ++command_num << ": ";
        cin >> type1 >> type1_num >> command_string >> type2 >> type2_num;

        // lower all the characters of type1 and type2

        int health{0};
        int damage{0};
        lower_function(type1);
        lower_function(type2);

        // determine who attacks to whom.

        if (type1 == "attacker_archer")
        {
            if (type2 == "defender_archer")
            {
                damage = attacker_archer[type1_num - 1].attack(defender_archer[type2_num - 1]);

                if (damage == -1)
                {
                    cout << type2 << " " << type2_num << " is dead!" << endl;
                }
                else if (damage == -2)
                {
                    cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                }
                else
                {
                    health = defender_archer[type2_num - 1].getHealth();
                    health = health - damage;
                    cout << "Damage given is: " << damage << endl;

                    if (health <= 0)
                    {
                        cout << type2 << " " << type2_num << " is dead!" << endl;
                    }
                    else
                    {
                        cout << " New health of " << type2 << " is: " << health << endl;
                    }

                    cout << "Number of arrows of " << type1 << " " << type1_num << " is: " << attacker_archer[type1_num - 1].get_nrOfArrows() << endl;

                    defender_archer[type2_num - 1].setHealth(health);
                }
            }
            else if (type2 == "defender_villager")
            {
                damage = attacker_archer[type1_num - 1].attack(defender_villager[type2_num - 1]);

                if (damage == -1)
                {
                    cout << type2 << " is dead!" << endl;
                }
                else if (damage == -2)
                {
                    cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                }
                else
                {
                    health = defender_villager[type2_num - 1].getHealth();
                    health = health - damage;
                    cout << "Damage given is: " << damage << endl;

                    if (health <= 0)
                    {
                        cout << type2 << " " << type2_num << " is dead!" << endl;
                    }
                    else
                    {
                        cout << "New health of " << type2 << " " << type2_num << " is: " << health << endl;
                    }

                    if (attacker_archer[type1_num - 1].get_nrOfArrows() == 0)
                    {
                        cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                    }
                    else
                    {
                        cout << "Number of arrows of " << type1 << " " << type1_num << " is: " << attacker_archer[type1_num - 1].get_nrOfArrows() << endl;
                    }

                    defender_villager[type2_num - 1].setHealth(health);
                }
            }
        }
        else if (type1 == "attacker_villager")
        {
            int returned_value;

            if (type2 == "defender_villager")
            {
                returned_value = attacker_villager[type1_num - 1].attack(defender_villager[type2_num - 1]);

                if (returned_value == 0)
                {
                    cout << "Villagers cannot attack!" << endl;
                }
            }
            else
            {
                cout << "Villagers cannot attack!" << endl;
            }
        }

    } while (!(type1 == type2 && type1_num == type2_num));

    // If types (Attacker Archer , Attacker Villager) and type_num's are equal which means same type and if the number is same same person
    // Assuming attacker archers cannot fight with each other when they are on the same team
    // Archers cannot attack their team members.
}

void defender_choice(Archer *attacker_archer, Archer *defender_archer, Villager *attacker_villager, Villager *defender_villager)
{
    cout << "Rules: " << endl;
    cout << "\nYou have choosen the defender team, attack by FIGHT command." << endl;
    cout << "\nSample defend command: Defender_Archer 1 FIGHT  Attacker_Villager 3" << endl;
    cout << "\nAttacker villagers cannot fight, they produce food for the defender archers." << endl;

    int command_num{0};
    string command_string{};

    string type1;
    int type1_num{};
    string type2;
    int type2_num{};

    do
    {
        cout << "Enter command #" << ++command_num << ": ";
        cin >> type1 >> type1_num >> command_string >> type2 >> type2_num;

        // lower all the characters of type1 and type2

        int health{0};
        int damage{0};
        lower_function(type1);
        lower_function(type2);

        // determine who attacks to whom.

        if (type1 == "defender_archer")
        {
            if (type2 == "attacker_archer")
            {
                damage = defender_archer[type1_num - 1].attack(attacker_archer[type2_num - 1]);

                if (damage == -1)
                {
                    cout << type2 << " " << type2_num << " is dead!" << endl;
                }
                else if (damage == -2)
                {
                    cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                }
                else
                {
                    health = attacker_archer[type2_num - 1].getHealth();
                    health = health - damage;
                    cout << "Damage given is: " << damage << endl;

                    if (health <= 0)
                    {
                        cout << type2 << " " << type2_num << " is dead!" << endl;
                    }
                    else
                    {
                        cout << "New health of " << type2 << " is: " << health << endl;
                    }

                    cout << "Number of arrows of " << type1 << " " << type1_num << " is: " << defender_archer[type1_num - 1].get_nrOfArrows() << endl;

                    attacker_archer[type2_num - 1].setHealth(health);
                }
            }
            else if (type2 == "attacker_villager")
            {
                damage = defender_archer[type1_num - 1].attack(attacker_villager[type2_num - 1]);

                if (damage == -1)
                {
                    cout << type2 << " " << type2_num << " is dead!" << endl;
                }
                else if (damage == -2)
                {
                    cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                }
                else
                {
                    health = attacker_villager[type2_num - 1].getHealth();
                    health = health - damage;
                    cout << "Damage given is: " << damage << endl;

                    if (health <= 0)
                    {
                        cout << type2 << " " << type2_num << " is dead!" << endl;
                    }
                    else
                    {
                        cout << "New health of " << type2 << " " << type2_num << " is: " << health << endl;
                    }

                    if (defender_archer[type1_num - 1].get_nrOfArrows() == 0)
                    {
                        cout << type1 << " " << type1_num << " is out of arrows!" << endl;
                    }
                    else
                    {
                        cout << "Number of arrows of " << type1 << " " << type1_num << " is: " << defender_archer[type1_num - 1].get_nrOfArrows() << endl;
                    }

                    attacker_villager[type2_num - 1].setHealth(health);
                }
            }
        }
        else if (type1 == "defender_villager")
        {
            int returned_value;

            if (type2 == "defender_villager")
            {
                returned_value = defender_villager[type1_num - 1].attack(attacker_villager[type2_num - 1]);

                if (returned_value == 0)
                {
                    cout << "Villagers cannot attack!" << endl;
                }
            }
            else
            {
                cout << "Villagers cannot attack!" << endl;
            }
        }

    } while (!(type1 == type2 && type1_num == type2_num));

    // If types (Attacker Archer , Attacker Villager) and type_num's are equal which means same type and if the number is same same person
    // Assuming attacker archers cannot fight with each other when they are on the same team
    // Archers cannot attack their team members.
}

void lower_function(string &char_type)
{
    for (size_t i = 0; i < char_type.size(); i++)
    {
        char_type[i] = tolower(char_type[i]);
    }
}