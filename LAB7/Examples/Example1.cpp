#include <iostream>

using namespace std;

class Base{
	
	private:
		int c{9};

	protected:
		int b{3};
	
	public:
		int a{1};

		void print()
		{
			cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
		}
	
	
};

class Derived : public Base{
	
};

int main(void){
	
	cout<<"Base Class"<<endl;
	Base b;
	
	b.print();
	b.a=999;
	b.print();
	
	//b.b=888; error b is a protected member
	//b.c=777; error c is a private member
	
	
	return 0;
}