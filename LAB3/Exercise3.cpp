#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	
	int scores[]{100,95,89,-1};
	
	cout<<"Value of scores: "<<scores<<endl;
	int num{10};
	int *score_ptr{scores};
	cout<<"Value of score_ptr: "<<score_ptr<<endl;
	
	cout<<"Array subscript notation----------"<<endl;
	cout<<scores[0]<<endl;
	cout<<scores[1]<<endl;
	cout<<scores[2]<<endl;
	
	cout<<"\nPointer subscript notation-----------"<<endl;
	cout<<score_ptr[0]<<endl;
	cout<<score_ptr[1]<<endl;
	cout<<score_ptr[2]<<endl;
	
	cout<<"\n------------------------"<<endl;
	
	while(*score_ptr!=-1)
	{
		cout<<*score_ptr<<endl;
		score_ptr++; //pointing to the second element in the scores[] array
	}
	
	cout<<"\n------------------"<<endl;
	
	score_ptr=scores;
	
	while(*score_ptr!=-1){
		cout<<""<<*(score_ptr++)<<endl;
	}
	
	
	
}