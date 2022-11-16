#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void menu();

class Contact{
	
	private:
		//attributes
		
		string name;
		string number;
		
		
	public:
		
		//constructors
		Contact();
		Contact(string name,string number);
		
		//methods:
		
		void print(string mode);
	
		//Setters:
		void set_name(string name);
		void set_number(string number);
	
		//Getters:
	
		string get_name(void);
		string get_number(void);
	
};

//Methods

string Contact::get_name(){
	return this->name;
}

string Contact::get_number(){
	return this->number;
}

void Contact::set_name(string name){
	this->name=name;
}

void Contact::set_number(string number){
	this->number=number;
}

void Contact::print(string mode){
	
	if(mode=="light")
	{
		cout<<setw(15)<<left<<name<<setw(15)<<left<<number<<endl;
	}
	else if(mode=="headers")
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Number: "<<number<<endl<<endl;
	}
	
}

//Constructors

Contact::Contact()
	:name{"Unknown"},number{"0"}{
	
}

Contact::Contact(string name,string number)
	:name{name},number{number}{
	
}

class AddressBook{
	
	private:
		//Attributes
		
		int nrofcontacts{0};
		Contact contacts[10];
		
		//Private methods:
		
		int search(string name);
	
	public:
		
		//Constructors:
		AddressBook();
		
		//Getters & setters
		Contact get_contacts(void);
		int get_nrofcontacts(void);
		
		void set_nrofcontacts(int nrofcontacts);
		
		//Methods
		bool add(Contact new_contact);
		bool remove(string name);
		void print();
	
};

//Constructor:
AddressBook::AddressBook(){
	
}

//Methods:


int AddressBook::search(string name){
	
	for(int i=0;i<nrofcontacts;i++)
	{
		if(contacts[i].get_name()==name)
		{
			return i;
		}
	}
	
	return -1;
}

Contact AddressBook::get_contacts(){
	return *contacts;	
}

int AddressBook::get_nrofcontacts(){
	return this->nrofcontacts;
}

void AddressBook::set_nrofcontacts(int nrofcontacts){
	this->nrofcontacts=nrofcontacts;
}

bool AddressBook::add(Contact new_contact){
	
	
	if(search(new_contact.get_name())==-1)
	{
		contacts[nrofcontacts]=new_contact; //copying the attributes of the new_contact to nrofcontacts'th element of the contacts.
			
		if(contacts[nrofcontacts].get_name()==new_contact.get_name()) //only checking if the name is equal if name is equal then they are equal
		{
			nrofcontacts++;
			return true;
		}
	}

	return false;	
	
}

bool AddressBook::remove(string name){
	
	if(search(name)!=-1) // if it's not -1 then it is returning a position index which means the name that we want to remove exists.
	{
		//shift the contacts array.
		
		int index=search(name);
		int size;
		
		size=nrofcontacts;
		
		for(int i=index;i<size;i++)
		{
			contacts[i]=contacts[i+1];
		}
		
		//cout<<"(before)nrofcontacts: "<<nrofcontacts<<endl;
		nrofcontacts--;
		//cout<<"(after)nrofcontacts: "<<nrofcontacts<<endl;
		
		
		return true;
	}
	
	
	return false; // since it hasn't entered the above if statement search(name) must be equal to -1 which means it does not exist
}

void AddressBook::print(){
	
	string ask;
	
	cout<<"Do you want to print same line (light) or different line (headers): ";
	cin>>ask;
	
	if(ask=="light")
	{
		cout<<endl;
		cout<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Number"<<endl;
	}
	
	for(int i=0;i<nrofcontacts;i++)
	{
		contacts[i].print(ask);
	}
	
}

int main(void){
	

	menu();
	
	return 0;
}

void menu(){
	
		AddressBook Address;
		int choice;
	
		do{
			
		cout<<"\n1. Display Address Book"<<endl;
		cout<<"2. Add new contact"<<endl;
		cout<<"3. Remove contact"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		
		if(choice==1)
		{
			int number=Address.get_nrofcontacts();
			if(number==0)
			{
				cout<<"No contacts available."<<endl<<endl;
			}
			else
			{
				Address.print();
			}
		}
		else if(choice==2)
		{
			Contact new_contact;
			string temp_name;
			string temp_number;
			bool check;
			
			cout<<"Enter name: ";
			cin>>temp_name;
			new_contact.set_name(temp_name);
			
			cout<<"Enter number: ";
			cin>>temp_number;
			new_contact.set_number(temp_number);
			
			check=Address.add(new_contact);
			
			
			if(check==true)
			{
				cout<<"Contact added."<<endl<<endl;
			}
			else
			{
				cout<<"Contact already exists."<<endl<<endl;
			}
		}
		else if(choice==3)
		{
			int number=Address.get_nrofcontacts();
			bool check;
			if(number==0)
			{
				cout<<"No contacts available."<<endl<<endl;
			}
			else
			{
				string temp_name;
				cout<<"Enter name: ";
				cin>>temp_name;
				check=Address.remove(temp_name);
				
				if(check==false)
				{
					cout<<"Contact is not available."<<endl<<endl;
				}
				else
				{
					cout<<"Contact removed."<<endl<<endl;
				}
			}
		}
		
		}while(choice!=4);

}