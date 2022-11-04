#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void swap_with_reff(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main(void){
	
	int x{8};
	int y{5};
	
	cout<<"x: "<<x<<" y: "<<y<<endl;
	swap(&x,&y);
	cout<<"x: "<<x<<" y: "<<y<<endl;
	
	cout<<"\n--------------------"<<endl;
	
	cout<<"With pass by reference: "<<endl;
	swap_with_reff(x,y);
	cout<<"x: "<<x<<" y: "<<y<<endl;
	
	
	cout<<endl;
	return 0;
}