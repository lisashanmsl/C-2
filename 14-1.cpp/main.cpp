#include<iostream>
#include<string>
#include"Administrator.h"
using namespace Company;

int main(void)
{
	//用子類別Administrator創建物件
	Administrator emp1("Dount", "1122-66655-4874", 5000.30, "Director", "Production", "Bob Smith");
	emp1.print();
	emp1.print_Check();

	//改變emp1中的資料
	emp1.set_name("Dick");
	emp1.set_ssn("5555-22288-4578");
	emp1.set_salary(12000.50);
	emp1.print();
	emp1.print_Check();

	Administrator emp2;
	emp2.read_admdata();
	emp2.print();
	emp2.print_Check();

	system("pause");
	return 0;
}