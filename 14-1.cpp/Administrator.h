//�w�qAdministrator�l���O�����禡(derived class�~�ө�SalariedEmployee�����O)
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
		string title;			//¾��
		string area;			//�t�d�ϰ�
		string supervisor;		//�D�ީm�W
	};

}//namespace Company
#endif // ADMINISTRATOR_H