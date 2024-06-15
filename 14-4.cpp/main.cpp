#include"UniversityStaff.h"
#include"Student.h"
#include"ScienceStudent.h"
#include<iostream>
#include<string>
using namespace Colleage;
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(void)
{
	UniversityStaff staff1("Dr.J");
	UniversityStaff staff2("Dr.H");

	Student student1("NTU", 112001, staff1);		//學生物件中最後一個引數傳入UniversityStaff物件
	Student student2("NCKU", 112002, staff2);		
	Student student3(student1);					//複製student1物件(copy constructor)
	Student student4 = student2;				//物件指派給物件(assign overload)
	

	ScienceStudent scistudent1("NYCU", 112005, staff2, "CSIE", "undergraduate");
	ScienceStudent scistudent2;

	scistudent2 = scistudent1;

	cout << "Student3:" << endl;
	cout << "University: " << student3.get_uniName() << endl;
	cout << "Registration number: " << student3.get_regNum() << endl;
	cout << "Proctor: " << student3.get_proctor() << endl << endl;

	cout << "Student4:" << endl;
	cout << "University: " << student4.get_uniName() << endl;
	cout << "Registration number: " << student4.get_regNum() << endl;
	cout << "Proctor: " << student4.get_proctor() << endl << endl;


	cout << "Science Student2:" << endl;
	cout << "University: " << scistudent2.get_uniName() << endl;
	cout << "Registration number: " << scistudent2.get_regNum() << endl;
	cout << "Proctor: " << scistudent2.get_proctor() << endl;
	cout << "Science Discipline: " << scistudent2.get_discipline() << endl;
	cout << "Course Type: " << scistudent2.get_courseType() << endl << endl;


	return 0;
}