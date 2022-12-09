#include <iostream>
#include <string>

using namespace std;

class UpDownNumbers{
	
	private:
		int start;
		int length;
		int *numbers;
	public:
		
		void print();
		void generate();
		UpDownNumbers(int length,int start);
		UpDownNumbers(UpDownNumbers &source);
		~UpDownNumbers();
		
		void set_start(int start){this->start=start;}
		void set_length(int length){this->length=length;}
		int get_start(void){return this->start;}
		int get_length(void){return this->length;}
		
};

void UpDownNumbers::print(){
	
	for(int k=0;k<length;k++)
	{
		cout<<numbers[k]<<" ";
	}
	
	cout<<endl;
	
}

void UpDownNumbers::generate(){
	
	numbers[0] = start;
	
	for(int i=1;i<length;i++)
	{
		if(numbers[i-1]%2 == 1)
		{
			numbers[i] = numbers[i-1]*3 - 1;	
		}
		else
		{
			numbers[i] = (numbers[i-1] / 2) + 5;
		}
	}
	
	
}

UpDownNumbers::UpDownNumbers(int length,int start)
	:start{start},length{length}{
	
	numbers = new int [length];
}

UpDownNumbers::UpDownNumbers(UpDownNumbers &source)
	:start{source.start},length{source.length}
	{
	
	numbers = new int [length];
	for(int i=0;i<source.length;i++)
	{
		this->numbers[i] = source.numbers[i];	
	}
	
}

UpDownNumbers::~UpDownNumbers(){
	delete [] numbers;
}

int main(void){
	
	int temp_start{0};
	int temp_length{0};
	

	//Getting attributes of object A via temp parameters.
	cout<<"Enter length and start for Object A: ";
	cin>>temp_length>>temp_start;

	//Object A is created.
	UpDownNumbers A(temp_length,temp_start);

	//Generating A object by calling its generate method.
	cout<<"Object A (start: "<<A.get_start()<<", length: "<<A.get_length()<<"): ";
	A.generate();
	A.print();
	
	
	UpDownNumbers B = A;
	cout<<"Object B (B = A): ";
	B.generate();
	B.print();
	
	
	cout<<"\nEnter new start for Object B: ";
	cin>>temp_start;
	
	B.set_start(temp_start);
	cout<<"B.set_start is: "<<B.get_start()<<endl;
	B.generate();
	cout<<"Object B: ";
	B.print();
	
	cout<<endl;
	
	cout<<"Object A (start: "<<A.get_start()<<", length: "<<A.get_length()<<"): ";
	A.print();
	cout<<"Object B (start: "<<B.get_start()<<", length: "<<B.get_length()<<"): ";
	B.print();
	
	return 0;
}