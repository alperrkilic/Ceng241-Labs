#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Course{
	
	private:
		
		//attributes
		string name{};
		string letterGrade{};
		
		int mtG;
		int hwG;
		int finG;
		
		double mtW;
		double hwW;
		double finW;

	
	public:
		

		
		
		//Constructors:
		Course();
		Course(double mtW,double hwW,double finW);
		
		//methods
		void calculate();
		
		//getters:
		
		string get_letterGrade();
		string get_name();
		int get_mtG();
		int get_hwG();
		int get_finG();
	
		//setters:
	
		void set_mtG(int mtG);
		void set_hwG(int hwG);
		void set_finG(int finG);
		void set_name(string name);
		
	
};

//Methods


void Course::calculate(){
	
	double temp_grade;
	
	temp_grade=(hwG*hwW)+(mtG*mtW)+(finG*finW);
	
	if(temp_grade>=90)
	{
		letterGrade="AA";
	}
	else if(temp_grade>=85 && temp_grade<90)
	{
		letterGrade="BA";
	}
	else if(temp_grade>=80 && temp_grade<85)
	{
		letterGrade="BB";
	}
	else if(temp_grade>=70 && temp_grade<80)
	{
		letterGrade="CB";
	}
	else if(temp_grade>=60 && temp_grade<70)
	{
		letterGrade="CC";
	}
	else if(temp_grade>=50 && temp_grade<60)
	{
		letterGrade="DC";
	}
	else if(temp_grade>=45 && temp_grade<50)
	{
		letterGrade="DD";
	}
	else if(temp_grade>=35 && temp_grade<45)
	{
		letterGrade="FD";
	}
	else
	{
		letterGrade="FF";
	}
	
}

//Constructors

Course::Course()
{	
	hwW=0.20;
	mtW=0.30;
	finW=0.50;	
}

Course::Course(double mtW,double hwW,double finW)
{
	this->hwW=hwW;
	this->mtW=mtW;
	this->finW=finW;	
}

//Getters

int Course::get_finG(){
	return finG;
}

int Course::get_mtG(){
	return mtG;
}

int Course::get_hwG(){
	return hwG;
}

string Course::get_name(){
	return name;
}

string Course::get_letterGrade(){
	return letterGrade;
}

//setters

void Course::set_finG(int finG){
	this->finG=finG;
}

void Course::set_mtG(int mtG){
	this->mtG=mtG;
}

void Course::set_hwG(int hwG){
	this->hwG=hwG;
}

void Course::set_name(string name){
	this->name=name;
}

int main(void){
	
	double homework_weight;
	double midterm_weight;
	double final_weight;
	string temp_name; //I will use it to assign the strings that user have inputted to my objects private attributes by setter functions
	int temp_hwG;
	int temp_mtG;
	int temp_finG;
	
	//Creating first_course object of the Course class with default constructor.
	Course first_course;
	
	cout<<"Enter weights for second course: ";
	cin>>midterm_weight>>homework_weight>>final_weight;
	
	//Creating second_course object of the Course class with 3-args-constructor.
	Course second_course(midterm_weight,homework_weight,final_weight);
	
	//First Course:
	//getting first_course name
	cout<<"Enter first course name: ";
	cin>>temp_name;
	first_course.set_name(temp_name);
	
	//getting first course grades and then setting them.
	cout<<"Enter first course grades: ";
	cin>>temp_mtG>>temp_hwG>>temp_finG;
	
	first_course.set_mtG(temp_mtG);
	first_course.set_hwG(temp_hwG);
	first_course.set_finG(temp_finG);
	
	//Second Course:
	cout<<"Enter second course name: ";
	cin>>temp_name;
	second_course.set_name(temp_name);
	
	cout<<"Enter second course grades: ";
	cin>>temp_mtG>>temp_hwG>>temp_finG;
	
	second_course.set_mtG(temp_mtG);
	second_course.set_hwG(temp_hwG);
	second_course.set_finG(temp_finG);
	
	//Calculating letter grades:
	
	first_course.calculate();
	second_course.calculate();
	
	//Printing the attributes in a table:
	
	cout<<endl;
	cout<<setw(15)<<left<<"Course"<<setw(15)<<left<<"Midterm"<<setw(15)<<left<<"Homework"<<setw(15)<<left<<"Final"<<setw(15)<<left<<"Letter"<<endl;
	cout<<setw(15)<<left<<first_course.get_name()<<setw(15)<<left<<first_course.get_mtG()<<setw(15)<<left<<first_course.get_hwG()<<setw(15)<<left<<first_course.get_finG()<<setw(15)<<left<<first_course.get_letterGrade()<<endl;
	cout<<setw(15)<<left<<second_course.get_name()<<setw(15)<<left<<second_course.get_mtG()<<setw(15)<<left<<second_course.get_hwG()<<setw(15)<<left<<second_course.get_finG()<<setw(15)<<left<<second_course.get_letterGrade()<<endl;

	
	return 0;
}