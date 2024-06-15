//SalariedEmployee類別的函式的功能
#include "SalariedEmployee.h"
#include <iostream>
using std::cout;

namespace Company {

	SalariedEmployee::SalariedEmployee() :name(" "), ssn(" "), salary(0.0) {}
	SalariedEmployee::SalariedEmployee(const string& name, const string& ssn, double salary)
	{
		this->name = name;
		this->ssn = ssn;
		this->salary = salary;
	}
	void SalariedEmployee::set_name(const string& name) { this->name = name; }
	void SalariedEmployee::set_ssn(const string& ssn) { this->ssn = ssn; }
	void SalariedEmployee::set_salary(double salary) { this->salary = salary; }

	string SalariedEmployee::get_name()const { return name; }
	string SalariedEmployee::get_ssn()const { return ssn; }
	double SalariedEmployee::get_salary()const { return salary; }

	void SalariedEmployee::print_Check()const
	{
		cout << "Error\n";
		exit(1);
	}

} // namespace Company
