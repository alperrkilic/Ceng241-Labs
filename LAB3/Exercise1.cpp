#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	
	int num{10};
	cout<<"Value of num is: "<<num<<endl;
	cout<<"Sizeof of num is: "<<sizeof num<<endl;
	cout<<"Address of num is: "<<&num<<endl;
	
	
	cout<<"\nPointer"<<endl;
	
	int *p{&num};
	cout<<"Value of p is: "<<p<<endl; //prints address of num variable
	cout<<"Sizeof of p is: "<<sizeof p<<endl;
	cout<<"Address of p is"<<&p<<endl;
	
	
	cout<<"\nScore Pointer"<<endl;
	
	int score{100};
	int *score_ptr{&score};
	
	cout<<*score_ptr<<endl;
	*score_ptr=200;
	cout<<*score_ptr<<endl;
	cout<<score<<endl;
	
	
	cout<<"\n-------------------------------"<<endl;
	
	vector <string> stooges {"Larry","Moe","Curly"};
	vector <string> *vector_ptr{nullptr};
	
	vector_ptr=&stooges;
	
	cout<<"First stooge: "<<(*vector_ptr).at(0)<<endl;
	
	cout<<"Stooges: ";
	
	for(auto stooge: *vector_ptr)
	{
		cout<<stooge<<" ";
	}
	cout<<endl;
	
	return 0;
}