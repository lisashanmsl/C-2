//定義ScienceStudent類別成員函式(子類別)
#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include"Student.h"
#include<string>
using std::string;

namespace Colleage {
	class ScienceStudent : public Student
	{
	public:
		ScienceStudent();
		ScienceStudent(const string& universityName, const int registNumber, UniversityStaff proctor, const string& discipline, const string& courseType);
		ScienceStudent(const ScienceStudent& object);

		void set_discipline(string& discipline);
		void set_courseType(string& courseType);

		string get_discipline()const;
		string get_courseType()const;

		ScienceStudent& operator=(const ScienceStudent& rightSide);

	private:
		string discipline;			//科學學科種類
		string courseType;			//課程型態(本科/研究生)
	};
}
#endif