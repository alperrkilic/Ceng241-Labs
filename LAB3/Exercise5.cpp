#include <iostream>
#include <vector>
#include <string>

using namespace std;

void doubleIt(int *p){
	(*p)*=2;
}

int main(void){
	
	int val{10};
	int *p1{nullptr};
	
	cout<<"Value: "<<val<<endl;
	doubleIt(&val);
	cout<<"Value: "<<val<<endl;
	
	
	cout<<"----------------------------"<<endl;
	
	p1=&val;
	doubleIt(&val);
	cout<<"Value: "<<val<<endl;
	
	
	
	cout<<endl;
	return 0;
}