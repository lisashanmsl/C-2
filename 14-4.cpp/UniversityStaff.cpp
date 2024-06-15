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
	in >> object.name;		//用輸入字串流讀入物件中的name
	return in;
}
ostream& operator<<(ostream& out, const UniversityStaff& object)
{
	out << object.name;		//用輸出字串流讀入物件中的name
	return out;
}