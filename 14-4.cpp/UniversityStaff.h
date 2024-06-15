//定義UniversityStaff類別成員函式
#ifndef	UNIVERSITYSTAFF_H
#define	UNIVERSITYSTAFF_H

#include<string>
using namespace std;

class UniversityStaff
{
public:
	UniversityStaff();
	UniversityStaff(const string& name);
	UniversityStaff(const UniversityStaff& object);

	void set_name(const string& name);
	string get_name()const;

	UniversityStaff& operator=(const UniversityStaff& rightSide);
	friend istream& operator>>(istream& in, UniversityStaff& object);
	friend ostream& operator<<(ostream& out, const UniversityStaff& object);

private:
	string name;
};
#endif
