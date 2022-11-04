#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	
	int *int_ptr{nullptr};
	int_ptr = new int;
	
	cout<<int_ptr<<endl; //address from heap
	delete int_ptr;
	
	
	size_t size{0};
	double *scores{nullptr};
	
	cout<<"Please enter number of students: ";
	cin>>size;
	
	scores = new double [size];
	cout<<scores<<endl;
	
	delete [] scores;
	
	
	cout<<endl;
	return 0;
}