#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct COURSE
{
	string course_name;
	double grade;
};

int main(void){
	
	char choice{};
	pair<string,double> value;
	double cgpa{0};
	double sum=0;
	
	vector<COURSE> student;
	
	do{
		COURSE course_info;
		
		cout<<"Enter course code and grade: ";
		cin>>course_info.course_name>>course_info.grade;
		
		student.push_back(course_info);
		
		cout<<"Add new course ? ";
		cin>>choice;
		
		
	}while(choice!='n' && choice!='N');
	
	
	size_t size;
	
	size=student.size();
	
	cout<<"\nList of entered "<<size<<" courses: "<<endl;
	
	for (auto &&i : student)
	{
		cout<<"- "<<i.course_name<<" "<<i.grade<<endl;
		sum+=i.grade;
	}
	
	
	//cout<<"\nsum: "<<sum<<endl;
	
	cgpa=sum/((1.0)*size);
	
	cout<<"CGPA: "<<cgpa<<endl;
	
	
	return 0;
	
}