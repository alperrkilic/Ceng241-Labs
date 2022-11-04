#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	
	string s1{"Ali"};
	string s2{"Ali"};
	string s3{"Veli"};
	
	string *p1={&s1};
	string *p2={&s2};
	string *p3={&s3};
	
	cout<<boolalpha;
	cout<<p1<<" == "<<p2<<" : "<<(p1==p2)<<endl; //since we are comparing addresses they are not equal.
	cout<<*p1<<" == "<<*p2<<" : "<<(*p1==*p2)<<endl;
	
	
	return 0;
}