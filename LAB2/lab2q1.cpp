#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	
	string file_name;
	
	cout<<"Enter file name: ";
	getline(cin,file_name);
	
	fstream user_file;
	
	user_file.open(file_name,ios::out); //write
	
	char choice{};

	
	if(user_file.is_open())
	{
		
		cout<<"Enter information to store.."<<endl;
		string add;
		
		do{
			getline(cin,add);
			user_file<<add<<"\n";
			
			
			cout<<"Want to enter more ? (y/n).. ";
			cin>>choice;
			cin.ignore();
		}while(choice!='n' && choice!='N');
		
		cout<<"\nThe information successfully stored in the file.."<<endl;
		user_file.close();
	}
	
	user_file.open(file_name,ios::in);
	char display{};
	string line;
	
	if(user_file.is_open())
	{
		cout<<"Want to see ? (y/n).. ";
		cin>>display;
		if(display=='y' || display=='Y')
		{
			cout<<"\nThis file contains:"<<endl;
			while(getline(user_file,line))
			{
				cout<<line<<endl;
			}
		}
		
		user_file.close();
	}
	
	
	return 0;
	
}