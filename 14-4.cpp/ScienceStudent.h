//�w�qScienceStudent���O�����禡(�l���O)
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
		string discipline;			//��ǾǬ����
		string courseType;			//�ҵ{���A(����/��s��)
	};
}
#endif