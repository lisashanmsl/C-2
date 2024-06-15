#include"ScienceStudent.h"
#include<string>
using std::string;

namespace Colleage {

	ScienceStudent::ScienceStudent() :Student(), discipline(" "), courseType(" "){}
	ScienceStudent::ScienceStudent(const string& universityName, const int registNumber, UniversityStaff proctor, const string& discipline, const string& courseType) :
		Student(universityName, registNumber, proctor)
	{
		this->discipline = discipline;
		this->courseType = courseType;
	}
	ScienceStudent::ScienceStudent(const ScienceStudent& object)
		:Student(object)		//父類別的建構子中傳入(接收)子類別的物件
	{
		this->discipline = object.get_discipline();
		this->courseType = object.get_courseType();
	}

	void ScienceStudent::set_discipline(string& discipline){ this->discipline = discipline; }
	void ScienceStudent::set_courseType(string& courseType){ this->courseType = courseType; }

	string ScienceStudent::get_discipline()const { return discipline; }
	string ScienceStudent::get_courseType()const { return courseType; }
	
	ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rightSide)
	{
		if (this != &rightSide) {
			Student::operator=(rightSide);					//使用父類別中的=多載的功能(傳入子類別的物件)
			this->discipline = rightSide.get_discipline();	//
			this->courseType = rightSide.get_courseType();	//
		}
		return *this;
	}
}