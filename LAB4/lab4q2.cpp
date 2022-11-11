#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee{
	
	private:
		double salary;
		double bonus;
		string name;
		int year;
		
	public:
		
		//methods
		void print();
		void calculateBonus();
		
		//setters
		void set_salary(double salary);
		void set_name(string name);
		void set_year(int year);
		
	
};

void Employee::print(){
	
	cout<<setw(15)<<left<<name<<setw(15)<<left<<year<<setw(15)<<left<<salary<<setw(15)<<left<<bonus<<endl;
	
}

void Employee::calculateBonus(){
	
	
	if(year<=5)
	{
		bonus=0;
	}
	else if(year>5 && year<=10)
	{
		bonus=salary*(0.05);
	}
	else if(year>10 && year<=15)
	{
		bonus=salary*(0.10);	
	}
	else if(year>15 && year<=20)
	{
		bonus=salary*(0.15);
	}
	else if(year>20)
	{
		bonus=salary*(0.20);
	}
	
	
}

void Employee::set_salary(double salary){
	this->salary=salary;
}

void Employee::set_name(string name){
	this->name=name;
}

void Employee::set_year(int year){
	this->year=year;
}

int main(void){
	
	int n;
	double salary;
	int year;
	string name;
	
	cout<<"Please enter number of workers: ";
	cin>>n;
		
	Employee *workers = new Employee[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter employee name, employed years and salary: ";
		cin>>name>>year>>salary;
		
		workers[i].set_name(name);
		workers[i].set_year(year);
		workers[i].set_salary(salary);
	}

	cout<<endl<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Years"<<setw(15)<<left<<"Salary"<<setw(15)<<left<<"Bonus"<<endl;
	
	for(int i=0;i<n;i++)
	{
		workers[i].calculateBonus();
		workers[i].print();
	}
	
	
	delete [] workers;
	
	return 0;
}