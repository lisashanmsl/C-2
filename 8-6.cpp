#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class MyInteger
{
public:
	MyInteger();
	MyInteger(int number);
	void set_integer(int number) { this->number = number; }
	int get_integer()const { return number; }
	int& operator[](int index);		//[]更

private:
	int number;
};

int main(void)
{
	MyInteger num1(418);

	cout << num1[0] << endl;
	cout << num1[1] << endl;
	cout << num1[2] << endl;
	cout << num1[3] << endl;
	
	system("pause");
	return 0;
}
MyInteger::MyInteger() :number(0) {}
MyInteger::MyInteger(int number) {
	this->number = number;
}
int& MyInteger::operator[](int index) {
	int length = 0;		
	int temp = number;	//number肚俱计
	int integer[10];

	
	while (temp > 0) {
		integer[length] = temp % 10;	//[0]琌俱计程计
		temp = temp / 10;
		length++;						//魁[1]
	}
	integer[length] = -1;				//禬计肚-1

	return integer[index];
}