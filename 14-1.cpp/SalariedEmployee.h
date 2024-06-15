//�w�qSalariedEmployee���O�����禡(base class)
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
using std::string;

namespace Company {
	class SalariedEmployee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(const string& name, const string& ssn, double salary);

		void set_name(const string& name);
		void set_ssn(const string& ssn);
		void set_salary(double salary);

		string get_name()const;
		string get_ssn()const;
		double get_salary()const;

		void print_Check()const;

	protected:
		string name;		//���u�m�W
		string ssn;			//�w���X
		double salary;		//�~��
	};

}//namespace Company
#endif //SALARIEDEMPLOYEE_H