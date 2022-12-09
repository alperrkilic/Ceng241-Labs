#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class CoffeeMachine
{
protected:
    int coffeeAmount;

public:
    CoffeeMachine();
    ~CoffeeMachine();
    void addCoffee(int num_of_cups);
    int get_coffeeAmount(void)
    {
        return this->coffeeAmount;
    }
};

// Constructor
CoffeeMachine::CoffeeMachine() : coffeeAmount{0}
{
}

// Destructor
CoffeeMachine::~CoffeeMachine()
{
}

// addCoffee method

void CoffeeMachine::addCoffee(int num_of_cups)
{
    coffeeAmount = coffeeAmount + num_of_cups;
}

class LatteMachine : public CoffeeMachine
{
private:
    int milkAmount;

public:
    LatteMachine();
    ~LatteMachine();
    void addMilk(int milk_num);
    int makeLatte(int num_of_cups);
    int get_milkAmount(void)
    {
        return this->milkAmount;
    }
};

// Constructor
LatteMachine::LatteMachine() : CoffeeMachine{}, milkAmount{0}
{
}

// Destructor
LatteMachine::~LatteMachine()
{
}

// addMilk method

void LatteMachine::addMilk(int milk_num)
{
    milkAmount = milkAmount + milk_num;
}

// makeLatte method

int LatteMachine::makeLatte(int num_of_cups)
{
    if (milkAmount >= num_of_cups && coffeeAmount >= num_of_cups && milkAmount != 0 && coffeeAmount != 0) // Which means there is enough coffee and milk to makeLatte
    {
        // Decrease amount of milk and coffee and return 0
        milkAmount -= num_of_cups;
        coffeeAmount -= num_of_cups;
        return 0;
    }
    else if (coffeeAmount < num_of_cups)
    {
        return -1;
    }
    else
    {
        return -2;
    }
}

class FilterCoffeeMachine : public CoffeeMachine
{
public:
    int makeFilterCoffee(int num_of_cups);
};

int FilterCoffeeMachine::makeFilterCoffee(int num_of_cups)
{
    if (coffeeAmount >= num_of_cups && coffeeAmount != 0)
    {
        coffeeAmount -= num_of_cups;
        return 0;
    }

    return -1; // there is not enough coffee.
}

void menu_function(void);
void lower_case_function(string &choice);
void latte_choice(LatteMachine &latte);
void filter_choice(FilterCoffeeMachine &filter_coffee);

int main(void)
{
    menu_function();
    return 0;
}

void menu_function(void)
{
    string choice;
    FilterCoffeeMachine filter_coffee;
    LatteMachine latte;

    cout << "Welcome To the Coffee Machine..." << endl;

    do
    {
        cout << "Filter or Latte ? : ";
        cin >> choice;
        lower_case_function(choice);

        if (choice == "filter")
        {
            filter_choice(filter_coffee);
        }
        else if (choice == "latte")
        {
            latte_choice(latte);
        }

    } while (choice != "none");

    cout << "Goodbye!" << endl;
}

void lower_case_function(string &choice)
{
    for (size_t i = 0; i < choice.size(); i++)
    {
        choice[i] = tolower(choice[i]);
    }
}

void filter_choice(FilterCoffeeMachine &filter_coffee)
{

    int num_cups_to_drink{0};
    int coffee_to_add{0};
    cout << "How many cups of coffee do you want? : ";
    cin >> num_cups_to_drink;
    int returned_value = filter_coffee.makeFilterCoffee(num_cups_to_drink);
    int temp{0};

    while (returned_value < 0)
    {

        cout << "Not enough coffee! " << endl;
        cout << "Please add coffee: ";
        cin >> coffee_to_add;
        filter_coffee.addCoffee(coffee_to_add);

        if (coffee_to_add < num_cups_to_drink && filter_coffee.get_coffeeAmount() < num_cups_to_drink)
        {
            cout << "Not enough Coffee Added to make " << num_cups_to_drink << " cups of coffee." << endl;
            while (coffee_to_add < num_cups_to_drink)
            {
                cout << "Please add coffee more than or equal to " << num_cups_to_drink - filter_coffee.get_coffeeAmount() << " :";
                cin >> temp;
                coffee_to_add += temp;
            }
            filter_coffee.addCoffee(coffee_to_add); // now we have enough coffee and we are ready to make coffee.
        }

        returned_value = filter_coffee.makeFilterCoffee(num_cups_to_drink);
    }

    cout << "Enjoy your coffee!" << endl;
}

void latte_choice(LatteMachine &latte)
{

    int coffee_to_add{0};
    int milk_to_add{0};
    int num_cups_to_drink{0};
    int returned_value;
    int temp{0};

    cout << "How many cups of coffee do you want? : ";
    cin >> num_cups_to_drink;

    returned_value = latte.makeLatte(num_cups_to_drink);

    while (returned_value < 0)
    {
        if (returned_value == -1)
        {
            cout << "Not enough coffee! " << endl;
            cout << "Please add coffee: ";
            cin >> coffee_to_add;
            latte.addCoffee(coffee_to_add);

            if (coffee_to_add < num_cups_to_drink && latte.get_coffeeAmount() < num_cups_to_drink)
            {
                cout << "Not enough Coffee Added to make " << num_cups_to_drink << " cups of coffee." << endl;
                while (coffee_to_add < num_cups_to_drink)
                {
                    cout << "Please add coffee more than or equal to " << num_cups_to_drink - latte.get_coffeeAmount() << " :";
                    cin >> temp;
                    coffee_to_add += temp;
                }
                latte.addCoffee(coffee_to_add);
            }

            // now we have enough coffee
        }
        else if (returned_value == -2)
        {
            cout << "Not enough milk! " << endl;
            cout << "Please add milk: ";
            cin >> milk_to_add;
            latte.addMilk(milk_to_add);

            if (milk_to_add < num_cups_to_drink && latte.get_milkAmount() < num_cups_to_drink)
            {
                cout << "Not enough Milk Added to make " << num_cups_to_drink << " cups of coffee." << endl;
                while (milk_to_add < num_cups_to_drink)
                {
                    cout << "Please add milk more than or equal to " << num_cups_to_drink - latte.get_milkAmount() << endl;
                    cin >> temp;
                    milk_to_add += temp;
                }
                latte.addMilk(milk_to_add);
            }
        }

        returned_value = latte.makeLatte(num_cups_to_drink);
    }

    cout << "Enjoy your coffee!" << endl;
}