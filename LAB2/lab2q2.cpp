#include <iostream>
#include <string>

using namespace std;

int main(void){
	
	string str;
	string search;
	
	cout<<"Enter any string first :: ";
	getline(cin,str);
	
	cout<<"\nEnter substring u want to search :: ";
	getline(cin,search);
	
	size_t position;
	
	position=str.find(search);
	
	if(position!= string::npos)
	{
		cout<<"The substring "<<"[ "<<search<<" ]"<<" is present in given string at position "<<"[ "<<position+1<<" ]"<<endl;
	}
	else
	{
		cout<<"String not found..."<<endl;
	}
	
	//position+1 is designed due to the output
	
}