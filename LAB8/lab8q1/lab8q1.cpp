#include <iostream>
#include <string>

using namespace std;

class calculator
{

    friend std::ostream &operator<<(std::ostream &os, const calculator &obj);
    friend std::istream &operator>>(std::istream &is, const calculator &obj);

private:
    float *numbers;
    int length;

public:
    // Constructors
    calculator(/* args */);
    calculator(int length);
    ~calculator();

    // Operators
    calculator &operator=(const calculator &rhs); // copy assignment operator
    calculator operator+(const calculator &rhs) const;
    calculator operator-(const calculator &rhs) const;
    calculator operator*(const calculator &rhs) const;
    calculator operator/(const calculator &rhs) const;

    int get_length(void);
};

int calculator::get_length(void)
{
    return this->length;
}

std::ostream &operator<<(std::ostream &os, const calculator &obj)
{
    for (size_t i = 0; i < obj.length; i++)
    {
        os << obj.numbers[i] << " ";
    }
    os << endl;
    return os;
}

std::istream &operator>>(std::istream &is, const calculator &obj)
{
    float *buff = new float[obj.length];

    for (size_t i = 0; i < obj.length; i++)
    {
        is >> buff[i];
    }

    for (size_t i = 0; i < obj.length; i++)
    {
        obj.numbers[i] = buff[i];
    }

    delete[] buff;
    return is;
}

calculator::calculator() : numbers{nullptr}, length{0}
{
}

calculator::~calculator()
{
    delete[] this->numbers;
}

calculator::calculator(int length)
{
    this->length = length;
    this->numbers = new float[length];
}

calculator &calculator::operator=(const calculator &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    this->length = rhs.length;
    this->numbers = new float[this->length];

    for (size_t i = 0; i < rhs.length; i++)
    {
        this->numbers[i] = rhs.numbers[i];
    }

    return *this;
}

calculator calculator::operator+(const calculator &rhs) const
{
    int temp_length;
    int lower_bound;
    int upper_bound;

    // performing this because the size of the arrays might differ
    // in order not to add non-existing members we should check lower bound
    if (this->length > rhs.length)
    {
        temp_length = this->length;
        lower_bound = rhs.length;
        upper_bound = this->length;
    }
    else if (rhs.length > this->length)
    {
        temp_length = rhs.length;
        lower_bound = this->length;
        upper_bound = rhs.length;
    }
    else if (rhs.length == this->length)
    {
        lower_bound = this->length;
        upper_bound = this->length;
        temp_length = this->length;
    }

    calculator temp(temp_length);

    for (size_t i = 0; i < lower_bound; i++)
    {
        temp.numbers[i] = this->numbers[i] + rhs.numbers[i];
    }

    if (upper_bound != lower_bound)
    {
        if (rhs.length > this->length)
        {
            for (size_t i = lower_bound; i < upper_bound; i++)
            {
                temp.numbers[i] = rhs.numbers[i];
            }
        }
        else
        {
            for (size_t i = lower_bound; i < upper_bound; i++)
            {
                temp.numbers[i] = this->numbers[i];
            }
        }
    }
    return temp;
}

calculator calculator::operator-(const calculator &rhs) const
{
    int temp_length;
    int lower_bound;
    int upper_bound;

    // performing this because the size of the arrays might differ
    // in order not to add non-existing members we should check lower bound
    if (this->length > rhs.length)
    {
        temp_length = this->length;
        lower_bound = rhs.length;
        upper_bound = this->length;
    }
    else if (rhs.length > this->length)
    {
        temp_length = rhs.length;
        lower_bound = this->length;
        upper_bound = rhs.length;
    }
    else if (rhs.length == this->length)
    {
        lower_bound = this->length;
        upper_bound = this->length;
        temp_length = this->length;
    }

    calculator temp(temp_length);

    for (size_t i = 0; i < lower_bound; i++)
    {
        temp.numbers[i] = this->numbers[i] - rhs.numbers[i];
    }

    if (upper_bound != lower_bound)
    {
        if (rhs.length > this->length)
        {
            for (size_t i = lower_bound; i < upper_bound; i++)
            {
                temp.numbers[i] = rhs.numbers[i];
            }
        }
        else
        {
            for (size_t i = lower_bound; i < upper_bound; i++)
            {
                temp.numbers[i] = this->numbers[i];
            }
        }
    }
    return temp;
}

calculator calculator::operator*(const calculator &rhs) const
{
    int temp_length;
    int lower_bound;
    int upper_bound;

    // performing this because the size of the arrays might differ
    // in order not to add non-existing members we should check lower bound
    if (this->length > rhs.length)
    {
        temp_length = this->length;
        lower_bound = rhs.length;
        upper_bound = this->length;
    }
    else if (rhs.length > this->length)
    {
        temp_length = rhs.length;
        lower_bound = this->length;
        upper_bound = rhs.length;
    }
    else if (rhs.length == this->length)
    {
        lower_bound = this->length;
        upper_bound = this->length;
        temp_length = this->length;
    }

    calculator temp(temp_length);

    for (size_t i = 0; i < lower_bound; i++)
    {
        temp.numbers[i] = this->numbers[i] * rhs.numbers[i];
    }

    if (upper_bound != lower_bound)
    {
        for (size_t i = lower_bound; i < upper_bound; i++)
        {
            temp.numbers[i] = 0;
        }
    }
    return temp;
}

calculator calculator::operator/(const calculator &rhs) const
{
    int temp_length;
    int lower_bound;
    int upper_bound;

    // performing this because the size of the arrays might differ
    // in order not to add non-existing members we should check lower bound
    if (this->length > rhs.length)
    {
        temp_length = this->length;
        lower_bound = rhs.length;
        upper_bound = this->length;
    }
    else if (rhs.length > this->length)
    {
        temp_length = rhs.length;
        lower_bound = this->length;
        upper_bound = rhs.length;
    }
    else if (rhs.length == this->length)
    {
        lower_bound = this->length;
        upper_bound = this->length;
        temp_length = this->length;
    }

    calculator temp(temp_length);

    for (size_t i = 0; i < lower_bound; i++)
    {
        temp.numbers[i] = this->numbers[i] / rhs.numbers[i];
    }

    if (upper_bound != lower_bound)
    {
        for (size_t i = lower_bound; i < upper_bound; i++)
        {
            temp.numbers[i] = 0;
        }
    }
    return temp;
}

void menu();
void perform_calculation(const calculator &set1, const calculator &set2);

int main(void)
{
    menu();
    return 0;
}

void menu()
{
    // calculator set1;
    // calculator set2;
    // calculator new_set;

    int temp_length;

    // for the first set
    cout << "Length of the first number set: ";
    cin >> temp_length;
    calculator set1(temp_length);

    cout << "Enter " << set1.get_length() << " numbers: ";
    cin >> set1;
    cout << "First set entered: " << set1 << endl;

    // for the second set
    cout << "Length of the second number set: ";
    cin >> temp_length;
    calculator set2(temp_length);

    cout << "Enter " << set2.get_length() << " numbers: ";
    cin >> set2;
    cout << "Second set entered: " << set2 << endl;

    perform_calculation(set1, set2); // calling perform_calculation function
}

void perform_calculation(const calculator &set1, const calculator &set2)
{
    cout << "Enter an operation to perform: ";
    string operation;
    cin >> operation;

    while (operation != "exit")
    {
        if (operation == "+")
        {
            calculator new_set = set1 + set2;
            cout << new_set;
        }
        else if (operation == "-")
        {
            calculator new_set = set1 - set2;
            cout << new_set;
        }
        else if (operation == "*")
        {
            calculator new_set = set1 * set2;
            cout << new_set;
        }
        else
        {
            calculator new_set = set1 / set2;
            cout << new_set;
        }
        cout << "Enter an operation to perform: ";
        cin >> operation;
    }
}