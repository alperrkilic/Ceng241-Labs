#include <iostream>
#include <string>
using namespace std;

class Calculator{
	
	private:
		//attributes
		int number1;
		int number2;
		string operator_str;
		double result;
	
	public:
		
		//methods
		void run();
		
		//setters
		void set_number1(int number1);
		void set_number2(int number2);
		void set_string(string operator_str);
		
		//getters
		int get_number1();
		int get_number2();
		string get_operator_str();
	
};


void Calculator::run(){
	
	if(operator_str=="subtract")
	{
		result=number2-number1;
	}
	else if(operator_str=="add")
	{
		result=number2+number1;
	}
	else if(operator_str=="multiply")
	{
		result=number2*number1;
	}
	else if(operator_str=="divide")
	{
		result=(double)number1/(double)number2;
	}
	
	cout<<"\nResult is: "<<result<<endl;
	
}

void Calculator::set_number1(int number1){
	this->number1=number1;
}

void Calculator::set_number2(int number2){
	this->number2=number2;
}

void Calculator::set_string(string operator_str){
	this->operator_str=operator_str;
}

int Calculator::get_number1(){
	return number1;
}

int Calculator::get_number2(){
	return number2;
}

string Calculator::get_operator_str(){
	return operator_str;
}


int main(void){
	
	Calculator calc;
	string empty{""};
	
	int numb1;
	int numb2;
	string op_str;
	
	
	cout<<"Enter your operation: ";
	cin>>op_str>>numb1>>empty>>numb2;
	
	calc.set_number1(numb1);
	calc.set_number2(numb2);
	calc.set_string(op_str);
	
	
	calc.run();
	
	
	return 0;
}