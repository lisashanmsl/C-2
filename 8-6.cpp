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
	int& operator[](int index);		//[]�h��

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
	int temp = number;	//number���ǤJ�����
	int integer[10];

	
	while (temp > 0) {
		integer[length] = temp % 10;	//[0]�O��ƪ��̫�@�ӼƦr
		temp = temp / 10;
		length++;						//����[1]
	}
	integer[length] = -1;				//�W�X�Ʀr���צ^��-1

	return integer[index];
}