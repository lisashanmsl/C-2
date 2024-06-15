//Administrator類別的函式的功能
#include "Administrator.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace Company {

    Administrator::Administrator() :SalariedEmployee(), title(" "), area(" "), supervisor(" "){}
    Administrator::Administrator(const string& name, const string& ssn, double salary, const string& title, const string& area, const string& supervisor)
        :SalariedEmployee(name, ssn, salary)
    {
        this->title = title;
        this->area = area;
        this->supervisor = supervisor;
    }
    void Administrator::set_supervisor(const string& supervisor)
    {
        this->supervisor = supervisor;
    }
    void Administrator::read_admdata()      //讀取員工資料
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ssn: ";
        cin >> ssn;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter working area: ";
        cin >> area;
        cout << "Enter Enter supervisor name: ";
        cin >> supervisor;
    }
    void Administrator::print()const
    {
        cout << "Name: " << name << endl;
        cout << "SSN: " << ssn << endl;
        cout << "Annual salary: " << salary << endl;
        cout << "Title: " << title << endl;
        cout << "Working area: " << area << endl;
        cout << "Supervisor name: " << supervisor << endl;
    }
    void Administrator::print_Check()
    {
        set_salary(salary);         //
        cout << "\n__________________\n";
        cout << "Pay to the order of " << name << endl;
        cout << "The sum of " << salary << " dollar" << endl;
        cout << "______________________\n";
        cout << "Check Stub not negotiable" << endl;
        cout << "Employee SSN: " << ssn << endl;
        cout << "Salaried Employee. Regular Pay: " << salary << endl;
        cout << "______________________\n" << endl;
    }

} //namespace Company