#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

static int check=0;

class NumbersClass{
	
	private:
		int *numbers;
		int length;
		bool isPrime(int num);
	public:
		//methods
		void print();
		void generate();
		void filter(string str);
		//Constructors
		NumbersClass();
		NumbersClass(int length);
		
		//Copy constructor
		NumbersClass(NumbersClass &source);
		
		void set_length(int length){this->length=length;}
		
};

//Methods

//Private:
bool NumbersClass::isPrime(int num){
	
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	
	return true;
}

//Public:

void NumbersClass::generate(){
	
	srand(time(NULL));
	
	for(int i=0;i<length;i++)
	{
		numbers[i] = 1000 + (rand() %9001);
	}
	
}

void NumbersClass::print(){
	
	for(int i=0;i<length;i++)
	{
		if(numbers[i]!=-1)
		{
			cout<<numbers[i]<<" ";
		}
	}
	
	cout<<endl;
}

void NumbersClass::filter(string str){
	
	if(str=="prime")
	{
		for(int i=0;i<length;i++)
		{
			if(isPrime(numbers[i])) //if it is prime then continue;
			{
				check++;
				continue;
			}
			else
			{
				numbers[i] = -1; // if it's not prime set the value to -1 as it is mentioned in the question
			}
		}
	}
	else if(str=="nonprime")
	{
		for(int i=0;i<length;i++)
		{
			if(isPrime(numbers[i])) //if it is prime set the value to -1
			{
				numbers[i] = -1;
			}
			else
			{
				continue; // if it's nonprime then continue;
			}
		}
	}
	
}

//Constructors:

NumbersClass::NumbersClass(int length)
	:length{length}{
	
	numbers = new int [length];
	
}

NumbersClass::NumbersClass(){
	
	length = 10;
	numbers = new int [length];
	
}

//Copy Constructors
NumbersClass::NumbersClass(NumbersClass &source)
	:length{source.length}
	{
	
	//Allocate new storage for numbers and then assign the value of source.numbers to numbers pointer
	//After that they both point the same value but in different areas in the heap.
	numbers = new int [length];
	
	//*numbers = *source.numbers;
	for(int i=0;i<source.length;i++)
	{
		this->numbers[i] = source.numbers[i];	
	}
	
}

int main(void){
	
	string prime{"prime"};
	string non_prime{"nonprime"};
	
	int temp_length;
	
	cout<<"Enter length: ";
	cin>>temp_length;
	
	NumbersClass A(temp_length);
	cout<<"\nA: ";
	A.generate();
	A.print();
	
	//copying A to B and C.
	NumbersClass B = A;
	B.filter(prime);
	NumbersClass C = A;
	C.filter(non_prime);	
	
	cout<<"\nB: ";
	if(check==0)
	{
		cout<<"No prime number."<<endl;
	}
	else
	{
		B.print();	
	}
	
	cout<<"\nC: ";
	C.print();
	
	return 0;
}