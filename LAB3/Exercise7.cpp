#include <iostream>
#include <vector>
#include <string>

using namespace std;

int *create_array(size_t n, int init_val)
{
	int *new_array{nullptr};
	
	new_array = new int [n];
	
	for(size_t i{0};i<n;i++)
	{
		*(new_array+i)=init_val;
	}
	
	return new_array;
	//it is in stack but it points to the heap
	//local variables take place in stack
	
}

void display(int *arr,size_t n){
	
	for(size_t i{0};i<n;++i)
	{
		cout<<*(arr+i)<<" ";
	}
	
}


int main(void){
	
	int *my_array{nullptr};
	size_t n;
	int init_val{0};
	cout<<"Input size: ";
	cin>>n;
	cout<<"What value would you like them to be initialized: ";
	cin>>init_val;
	

	my_array=create_array(n,init_val);
	
	display(my_array,n);
	
	delete [] my_array; 
	
	cout<<endl;
	return 0;
}