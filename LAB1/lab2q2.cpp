#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void){
	
	struct car{
		string car_name;
		int total_distance;
		int last_km;
		string check;
	}cars[5];
	
	//since I have to get 5 car's information I need to create an array struct to keep them.
	
	for(int i{0}; i<5; i++)
	{
		cout<<"Enter car model: ";
		getline(cin,cars[i].car_name);
		cout<<"Enter total distance: ";
		cin>>cars[i].total_distance;
		cout<<"Enter last km: ";
		cin>>cars[i].last_km;
		cin.ignore();
		
		if(((cars[i].total_distance)-(cars[i].last_km))>10000) // if total distance - last km is bigger than 10000 the car needs maintenance.
		{
			cars[i].check="YES";
		}
		else
		{
			cars[i].check="NO";
		}
	}

	cout<<"\n";
	cout<<setw(20)<<left<<"Car"<<setw(20)<<left<<"Total km"<<setw(20)<<left<<"Last km"<<setw(20)<<left<<"Needs Maintenance"<<endl;
	
	for(int i{0}; i<5; i++)
	{
		cout<<setw(20)<<left<<cars[i].car_name<<setw(20)<<left<<cars[i].total_distance<<setw(20)<<left<<cars[i].last_km<<setw(20)<<left<<cars[i].check<<endl;
	}

}