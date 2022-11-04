#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct COURSE
{
    vector<string> course_name;
    vector<double> grade;
};

int main(void){
	
	char choice{};
	pair<string,double> value;
	double cgpa{0};
	double sum=0;
	
	COURSE student;
	
	do{
		
		cout<<"Enter course code and grade: ";
		cin>>value.first>>value.second;
		
		student.course_name.push_back(value.first);
		student.grade.push_back(value.second);
		
		cin.ignore();
		
		cout<<"Add new course ? ";
		cin>>choice;
		
		
	}while(choice!='n' && choice!='N');
	
	
	size_t size;
	
	size=student.course_name.size();
	
	cout<<"\nList of entered "<<size<<" courses: "<<endl;
	
	for(int i=0;i<size;i++)
	{
		cout<<"- "<<student.course_name[i]<<" "<<student.grade[i]<<endl;
	}
	
	for(int i=0;i<size;i++)
	{
		sum=sum+student.grade[i];
	}
	
	
	//cout<<"\nsum: "<<sum<<endl;
	
	cgpa=sum/((1.0)*size);
	
	cout<<"CGPA: "<<cgpa<<endl;
	
	
	return 0;
	
}