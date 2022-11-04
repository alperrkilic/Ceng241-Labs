#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void){
	
	string str;
	
	cout<<"Enter a line of string: ";
	getline(cin,str);
	
	size_t size = str.size();
	
	
	int digit_counter{0};
	int vowel_counter{0};
	int white_space{0};
	int consonant_counter{0};
	
	
	for(int i{0};i<size;i++)
	{
		if(str[i]=='1' || str[i]=='2' || str[i]=='3' || str[i]=='4' || str[i]=='5' || str[i]=='6' || str[i]=='7' || str[i]=='8' || str[i]=='9' || str[i]=='0')
		{
			digit_counter++;	
		}
		else if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='I' || str[i]=='i' || str[i]=='o' || str[i]=='O' || str[i]=='U' || str[i]=='u')
		{
			vowel_counter++;
		}
		else if(str[i]==' ')
		{
			white_space++;
		}
		else
		{
			consonant_counter++;
		}
	}
	
	cout<<"\nVowels: "<<vowel_counter<<endl;
	cout<<"Consonants: "<<consonant_counter<<endl;
	cout<<"Digits: "<<digit_counter<<endl;
	cout<<"White spaces: "<<white_space<<endl;
	
	
	
}