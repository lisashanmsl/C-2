#include"UniversityStaff.h"
#include<iostream>
#include<string>
using namespace std;

UniversityStaff::UniversityStaff() :name(" "){}
UniversityStaff::UniversityStaff(const string& name)
{
	this->name = name;
}
UniversityStaff::UniversityStaff(const UniversityStaff& object)
{
	this->name = object.get_name();
}

void UniversityStaff::set_name(const string& name) { this->name = name; }
string UniversityStaff::get_name()const { return name; }

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rightSide)
{
	if (this != &rightSide) {
		this->name = rightSide.get_name();
	}
	return *this;
}

istream& operator>>(istream& in, UniversityStaff& object)
{ 
	in >> object.name;		//�ο�J�r��yŪ�J���󤤪�name
	return in;
}
ostream& operator<<(ostream& out, const UniversityStaff& object)
{
	out << object.name;		//�ο�X�r��yŪ�J���󤤪�name
	return out;
}