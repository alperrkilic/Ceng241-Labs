#include <iostream>

using namespace std;

int main(void){
	
	int N{0};
	char* letter_array{nullptr};
	int* letter_count_array{nullptr};
	
	
	cout<<"How many numbers letters are you going to enter? ";
	cin>>N;
	
	letter_array = new char[N];
	letter_count_array = new int[N];
	
	for(int i=0;i<N;i++)
	{
		cout<<"Enter letter and how many times it will be repeated: ";
		cin>>letter_array[i]>>letter_count_array[i];
	}
	
	cout<<endl;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<letter_count_array[i];j++)
		{
			cout<<letter_array[i];
		}
	}
	
	
	delete [] letter_array;
	delete [] letter_count_array;
	
	
	return 0;
	
}