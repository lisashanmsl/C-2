//Student類別的函式的功能
#include"Student.h"
#include<string>
using std::string;

namespace Colleage {

	Student::Student() :universityName(" "), registNumber(0), proctor(){}
	Student::Student(const string& universityName, const int registNumber, UniversityStaff proctor)
	{
		this->universityName = universityName;
		this->registNumber = registNumber;
		this->proctor = proctor;
	}
	Student::Student(const Student& object)						//可接收子類別的物件
	{
		this->universityName = object.get_uniName();
		this->registNumber = object.get_regNum();
		this->proctor = object.get_proctor();
	}
	void Student::set_uniName(const string& uniName) { universityName = uniName; }
	void Student::set_regNum(const int regNum){ registNumber = regNum; }
	void Student::set_proctor(UniversityStaff proctor) { this->proctor = proctor; }

	string Student::get_uniName()const { return universityName; }
	int Student::get_regNum()const { return registNumber; }
	UniversityStaff Student::get_proctor()const { return proctor; }

	Student& Student::operator=(const Student& rightSide)		//可傳入子類別的物件作為引數
	{
		if (this != &rightSide) {
			this->universityName = rightSide.universityName;	//
			this->registNumber = rightSide.registNumber;		//
			this->proctor = rightSide.proctor;					//
		}
		return *this;
	}
}