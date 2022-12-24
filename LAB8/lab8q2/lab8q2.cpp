#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Base Class Car:
class Car
{
protected:
    string brand_name;
    int model_year;
    int price;
    int total_cost;

public:
    // Constructors:
    Car();
    Car(string brand_name, int model_year, int price);
    Car(const Car &source);

    // Getters & setters

    void set_brand_name(string brand_name);
    void set_model_year(int model_year);
    void set_price(int price);
    void set_total_cost(int total_cost);

    string get_brand_name(void);
    int get_model_year();
    int get_price();
    int get_total_cost();

    // Destructor
    ~Car();
};

Car::Car() : brand_name{"Car"}, model_year{0}, price{0}, total_cost{0}
{
}

Car::Car(string brand_name, int model_year, int price) : brand_name{brand_name}, model_year{model_year}, price{price}, total_cost{0}
{
}

Car::Car(const Car &source) // Copy Constructor
{
    this->brand_name = source.brand_name;
    this->model_year = source.model_year;
    this->price = source.price;
    this->total_cost = source.total_cost;
}

void Car::set_brand_name(string brand_name)
{
    this->brand_name = brand_name;
}

void Car::set_model_year(int model_year)
{
    this->model_year = model_year;
}

void Car::set_price(int price)
{
    this->price = price;
}

void Car::set_total_cost(int total_cost)
{
    this->total_cost = total_cost;
}

string Car::get_brand_name(void)
{
    return this->brand_name;
}

int Car::get_model_year(void)
{
    return this->model_year;
}

int Car::get_price(void)
{
    return this->price;
}

int Car::get_total_cost(void)
{
    return this->total_cost;
}

Car::~Car()
{
}

// Electric_car Class
// Because of the diamond shape problem Electric car MUST inherit virtually from the base Car Class
class Electric_car : virtual public Car
{
    friend ostream &operator<<(ostream &os, const Electric_car &obj);

protected:
    int number_of_batteries;
    int electric_cost;

public:
    // Constructors
    Electric_car();
    Electric_car(string brand_name, int model_year, int price, int number_of_batteries, int electric_cost);
    Electric_car(const Electric_car &source);

    // Methods (Setters & getters):

    void set_electric_cost(int electric_cost);
    void set_number_of_batteries(int number_of_batteries);

    int get_electric_cost(void);
    int get_number_of_batteries(void);

    ~Electric_car();
};

ostream &operator<<(ostream &os, const Electric_car &obj)
{
    os << left << setw(15) << obj.brand_name << left << setw(16) << obj.model_year << left << setw(15) << obj.price << left << setw(17)
       << obj.number_of_batteries << left << setw(15) << obj.electric_cost << endl;
    return os;
}

Electric_car::Electric_car() : Electric_car{"Electric_car", 0, 0, 0, 0} // Delegating from overloaded constructor
{
}

Electric_car::Electric_car(string brand_name, int model_year, int price, int number_of_batteries, int electric_cost)
    : Car{brand_name, model_year, price}, number_of_batteries{number_of_batteries}, electric_cost{electric_cost}
{
    this->total_cost = this->electric_cost;
}

Electric_car::Electric_car(const Electric_car &source)
{
    // Since there is no raw pointers, shallow copying will be enough.
    this->brand_name = source.brand_name;
    this->model_year = source.model_year;
    this->price = source.price;
    this->electric_cost = source.electric_cost;
    this->number_of_batteries = source.number_of_batteries;
    this->total_cost = source.total_cost;
}

void Electric_car::set_electric_cost(int electric_cost)
{
    this->electric_cost = electric_cost;
}

void Electric_car::set_number_of_batteries(int number_of_batteries)
{
    this->number_of_batteries = number_of_batteries;
}

int Electric_car::get_electric_cost(void)
{
    return this->electric_cost;
}

int Electric_car::get_number_of_batteries(void)
{
    return this->number_of_batteries;
}

Electric_car::~Electric_car()
{
}

// Gasoline_car
// As same as the Electric_car Gasoline_car class MUST inherit virtually from base class Car
class Gasoline_car : virtual public Car
{
    friend ostream &operator<<(ostream &os, const Gasoline_car &obj);

protected:
    int engine_volume;
    int fuel_cost;

public:
    // Constructors
    Gasoline_car();
    Gasoline_car(string brand_name, int model_year, int price, int engine_volume, int fuel_cost);
    Gasoline_car(const Gasoline_car &source); // Copy constructor

    // Getters & Setters:

    void set_engine_volume(int engine_volume);
    void set_fuel_cost(int fuel_cost);

    int get_engine_volume(void);
    int get_fuel_cost(void);

    // Destructor
    ~Gasoline_car();
};

ostream &operator<<(ostream &os, const Gasoline_car &obj)
{
    os << left << setw(15) << obj.brand_name << left << setw(16) << obj.model_year << left << setw(15) << obj.price << left << setw(15)
       << obj.engine_volume << left << setw(15) << obj.fuel_cost << endl;
    return os;
}

Gasoline_car::Gasoline_car() : Gasoline_car{"Gasoline_car", 0, 0, 0, 0} // Delegating from overloaded constructor
{
}

Gasoline_car::Gasoline_car(string brand_name, int model_year, int price, int engine_volume, int fuel_cost)
    : Car(brand_name, model_year, price), engine_volume{engine_volume}, fuel_cost{fuel_cost}
{
    this->total_cost = this->fuel_cost;
}

Gasoline_car::Gasoline_car(const Gasoline_car &source)
{
    this->brand_name = source.brand_name;
    this->model_year = source.model_year;
    this->price = source.price;
    this->engine_volume = source.engine_volume;
    this->fuel_cost = source.fuel_cost;
    this->total_cost = source.total_cost;
}

void Gasoline_car::set_engine_volume(int engine_volume)
{
    this->engine_volume = engine_volume;
}

void Gasoline_car::set_fuel_cost(int fuel_cost)
{
    this->fuel_cost = fuel_cost;
}

int Gasoline_car::get_engine_volume(void)
{
    return this->engine_volume;
}

int Gasoline_car::get_fuel_cost(void)
{
    return this->fuel_cost;
}

Gasoline_car::~Gasoline_car()
{
}

// Hybrid_car Class inherits from both Electric_car and Gasoline_car
class Hybrid_car : public Electric_car, Gasoline_car
{
    friend ostream &operator<<(ostream &os, const Hybrid_car &obj);

public:
    // Constructors
    Hybrid_car();
    Hybrid_car(string brand_name, int model_year, int price, int engine_volume, int fuel_cost, int number_of_batteries, int electric_cost);
    Hybrid_car(const Hybrid_car &source);

    // Destructor
    ~Hybrid_car();
};

ostream &operator<<(ostream &os, const Hybrid_car &obj)
{
    os << left << setw(15) << obj.brand_name << left << setw(16) << obj.model_year << left << setw(19) << obj.price << left << setw(15) << obj.number_of_batteries
       << left << setw(20) << obj.electric_cost << left << setw(19) << obj.engine_volume << left << setw(16) << obj.fuel_cost << left << setw(5) << obj.total_cost << endl;
    return os;
}

Hybrid_car::Hybrid_car() : Gasoline_car{"Hybrid_car", 0, 0, 0, 0}
{
    this->number_of_batteries = 0;
    this->electric_cost = 0;
    this->total_cost = electric_cost + fuel_cost;
}

Hybrid_car::Hybrid_car(string brand_name, int model_year, int price, int engine_volume, int fuel_cost, int number_of_batteries, int electric_cost)
    : Gasoline_car{}
{
    this->brand_name = brand_name;
    this->model_year = model_year;
    this->price = price;
    this->engine_volume = engine_volume;
    this->fuel_cost = fuel_cost;
    this->number_of_batteries = number_of_batteries;
    this->electric_cost = electric_cost;
    this->total_cost = electric_cost + fuel_cost;
}

Hybrid_car::Hybrid_car(const Hybrid_car &source)
{
    this->brand_name = source.brand_name;
    this->model_year = source.model_year;
    this->price = source.price;
    this->engine_volume = source.engine_volume;
    this->fuel_cost = source.fuel_cost;
    this->number_of_batteries = source.number_of_batteries;
    this->electric_cost = source.electric_cost;
    this->total_cost = source.total_cost;
}

Hybrid_car::~Hybrid_car()
{
}

int main(void)
{
    vector<Electric_car> electric_cars;
    vector<Gasoline_car> gasoline_cars;
    vector<Hybrid_car> hybrid_cars;

    int choice{0};

    do
    {
        string brand_name;
        int model_year, price, electric_cost, number_of_batteries, fuel_cost, engine_volume;

        cout << "1- Electric Car" << endl;
        cout << "2- Gasoline Car" << endl;
        cout << "3- Hybrid Car" << endl;
        cout << "4- Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) // Electric_car Class
        {
            cout << "Enter brand name: ";
            cin >> brand_name;

            cout << "Enter model year: ";
            cin >> model_year;

            cout << "Price: ";
            cin >> price;

            cout << "Number of Batteries: ";
            cin >> number_of_batteries;

            cout << "Electric cost: ";
            cin >> electric_cost;

            electric_cars.push_back(Electric_car(brand_name, model_year, price, number_of_batteries, electric_cost));
        }
        else if (choice == 2) // Gasoline_car Class
        {
            cout << "Enter brand name: ";
            cin >> brand_name;

            cout << "Enter model year: ";
            cin >> model_year;

            cout << "Price: ";
            cin >> price;

            cout << "Engine Volume(CC): ";
            cin >> engine_volume;

            cout << "Fuel cost: ";
            cin >> fuel_cost;

            gasoline_cars.push_back(Gasoline_car(brand_name, model_year, price, engine_volume, fuel_cost));
        }
        else if (choice == 3) // Hybrid_car Class
        {
            cout << "Enter brand name: ";
            cin >> brand_name;

            cout << "Enter model year: ";
            cin >> model_year;

            cout << "Price: ";
            cin >> price;

            cout << "Number of Batteries: ";
            cin >> number_of_batteries;

            cout << "Electric cost: ";
            cin >> electric_cost;

            cout << "Engine Volume(CC): ";
            cin >> engine_volume;

            cout << "Fuel cost: ";
            cin >> fuel_cost;

            hybrid_cars.push_back(Hybrid_car(brand_name, model_year, price, engine_volume, fuel_cost, number_of_batteries, electric_cost));
        }

    } while (choice != 4);

    // Printing Cars:

    int car_num;
    car_num = electric_cars.size() + gasoline_cars.size() + hybrid_cars.size();

    cout << "List of " << car_num << " cars: " << endl
         << endl;

    int count{0};
    int minimum{0};
    Car *car{nullptr}; // will point the minimum

    if (electric_cars.size() != 0)
    {
        cout << "Electric Cars:" << endl;
        cout << left << setw(15) << "Brand Name" << left << setw(20) << "Model Year" << left << setw(15) << "Price" << left << setw(15)
             << "Batteries" << left << setw(15) << "Electric Cost" << endl;

        minimum = electric_cars[0].get_total_cost();
        car = &electric_cars[0];

        for (auto i : electric_cars)
        {
            if (electric_cars[count].get_total_cost() < minimum)
            {
                minimum = electric_cars[count].get_total_cost();
                car = &electric_cars[count];
            }
            cout << ++count << " - " << i << endl;
        }
    }

    if (gasoline_cars.size() != 0)
    {
        cout << "Gasoline Cars:" << endl;
        cout << left << setw(15) << "Brand Name" << left << setw(20) << "Model Year" << left << setw(15) << "Price" << left << setw(15)
             << "Engine Volume" << left << setw(15) << "Fuel Cost" << endl;

        if (minimum == 0 && car == nullptr) // No electric car exist.
        {
            minimum = gasoline_cars[0].get_total_cost();
            car = &gasoline_cars[0];
        }

        count = 0;
        for (auto i : gasoline_cars)
        {
            if (gasoline_cars[count].get_total_cost() < minimum)
            {
                minimum = gasoline_cars[count].get_total_cost();
                car = &gasoline_cars[count];
            }
            cout << ++count << " - " << i << endl;
        }
    }

    if (hybrid_cars.size() != 0)
    {
        cout << "Hybrid Cars:" << endl;
        cout << left << setw(15) << "Brand Name" << left << setw(20) << "Model Year" << left << setw(15) << "Price" << left << setw(15)
             << "Batteries" << left << setw(20) << "Electric Cost" << left << setw(20)
             << "Engine Volume" << left << setw(15) << "Fuel Cost" << left << setw(15) << "Total Cost" << endl;

        if (minimum == 0 && car == nullptr) // No electric and gasoline car exist.
        {
            minimum = hybrid_cars[0].get_total_cost();
            car = &hybrid_cars[0];
        }

        count = 0;
        for (auto i : hybrid_cars)
        {
            if (hybrid_cars[count].get_total_cost() < minimum)
            {
                minimum = hybrid_cars[count].get_total_cost();
                car = &hybrid_cars[count];
            }
            cout << ++count << " - " << i << endl;
        }
    }

    // Printing the lowest total price and brand.

    cout << car->get_brand_name() << " has the minimum cost of all cars with cost: " << car->get_total_cost() << endl;

    return 0;
}