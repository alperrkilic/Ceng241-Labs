#include <iostream>
#include <string>

using namespace std;


struct NUMBERLIST{
		
	int number_array[10];
	string direction;
	
};

void ptrFunction(NUMBERLIST *pointer_output);
void refFunction(NUMBERLIST &reference_output);


int main(void){
	
	NUMBERLIST pointer_output;
	NUMBERLIST reference_output;
	
	//For the pointer function
	
	cout<<"Enter 10 integers and order of summation: ";
	
	for(int i{0};i<10;i++)
	{
		cin>>pointer_output.number_array[i];
		if(i==9)
		{
			cin>>pointer_output.direction;
		}
	}
	
	cout<<"Result: ";
	
	ptrFunction(&pointer_output);
	
	//Printing the result within the main after calling ptrFunction
	for(int i{0};i<10;i++)
	{
		cout<<pointer_output.number_array[i]<<" ";
	}
	
	
	//For the reference function
	
	cout<<"\nEnter 10 integers and order of summation: ";
	
	for(int i{0};i<10;i++)
	{
		cin>>reference_output.number_array[i];
		if(i==9)
		{
			cin>>reference_output.direction;
		}
	}
	
	cout<<"Result: ";
	
	refFunction(reference_output);
	
	//Printing the result within the main for the reference_output
	for(int i{0};i<10;i++)
	{
		cout<<reference_output.number_array[i]<<" ";
	}
	
	return 0;
	
}


void refFunction(NUMBERLIST &reference_output)
{
		
	int sum{0};
	int k=0;
	int reverse_print_array[10];
	
	if(reference_output.direction == "left-to-right")
	{
		for(int i{0};i<10;i++)
		{
			sum=sum+reference_output.number_array[i];
			reference_output.number_array[i]=sum;
		}
	}
	else if(reference_output.direction == "right-to-left")
	{
		for(int i{9};i>=0;i--)
		{
			sum=sum+reference_output.number_array[i];
			k=i;
			reverse_print_array[k]=sum;
		}
		for(int i=0;i<10;i++)
		{
			reference_output.number_array[i]=reverse_print_array[i];
		}
	}
	
	
}

void ptrFunction(NUMBERLIST *pointer_output)
{
	
	int sum{0};
	int k=0;
	int reverse_print_array[10];
	
	if(pointer_output->direction == "left-to-right")
	{
		for(int i{0};i<10;i++)
		{
			sum=sum+pointer_output->number_array[i];
			pointer_output->number_array[i]=sum;
		}
	}
	else if(pointer_output->direction == "right-to-left")
	{
		for(int i{9};i>=0;i--)
		{
			sum=sum+pointer_output->number_array[i];
			k=i;
			reverse_print_array[k]=sum;
		}
		for(int i=0;i<10;i++)
		{
			pointer_output->number_array[i]=reverse_print_array[i];
		}
	}
}						