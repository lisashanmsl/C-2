//定義Administrator子類別成員函式(derived class繼承於SalariedEmployee父類別)
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"
#include <string>

namespace Company {
	class Administrator : public SalariedEmployee
	{
	public:
		Administrator();
		Administrator(const string& name, const string& ssn, double salary, const string& title, const string& area, const string& superviser);

		void set_supervisor(const string& supervisor);
		void read_admdata();
		void print()const;
		void print_Check();		//override

	protected:
		string title;			//職稱
		string area;			//負責區域
		string supervisor;		//主管姓名
	};

}//namespace Company
#endif // ADMINISTRATOR_H