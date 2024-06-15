//�w�qStudent���O�����禡(base class)
#ifndef STUDENT_H
#define STUDENT_H

#include"UniversityStaff.h"
#include<string>
using std::string;

namespace Colleage {
	class Student
	{
	public:
		Student();
		Student(const string& universityName, const int registNumber, UniversityStaff proctor);
		Student(const Student& object);

		void set_uniName(const string& uniName);
		void set_regNum(const int regNum);
		void set_proctor(UniversityStaff proctor);

		string get_uniName()const;
		int get_regNum()const;
		UniversityStaff get_proctor()const;

		Student& operator=(const Student& rightSide);

	private:
		string universityName;		//�j�ǦW��
		int registNumber;			//���U���X
		UniversityStaff proctor;	//����@�������ܼ�	
	};
}
#endif