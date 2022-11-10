#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account{
	
	private:
		//private attributes
		string name;
		double balance;
	
	public:
		
		//setters
		void set_balance(double balance);
		void set_name(string name);
	
		//getters:
		double get_balance();
		string get_name();
	
};

double Account::get_balance(){
	return this->balance;
}

string Account::get_name(){
	return this->name;
}

void Account::set_balance(double balance){
	this->balance=balance;
}

void Account::set_name(string name){
	this->name=name;
}

int main(void){
	
	Account acc;
	string empty1{"Balance"};
	string empty2{"Name"};
	double balance{3000};
	string name;
	Account *acc2;
	
	cout<<"Account: "<<&acc<<endl<<endl;
	
	acc.set_balance(1000);
	acc.set_name("Alper");
	
	cout<<setw(15)<<left<<empty1<<setw(15)<<left<<empty2<<endl;
	cout<<setw(15)<<left<<acc.get_name()<<setw(15)<<left<<acc.get_balance()<<endl;
	
	acc2 = new Account;
	acc2->set_name("Bayram");
	acc2->set_balance(balance);
	
	cout<<setw(15)<<left<<acc2->get_name()<<setw(15)<<left<<acc2->get_balance()<<endl;
	
	
	delete acc2;
	
	return 0;
}