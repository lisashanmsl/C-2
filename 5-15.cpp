#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	int pin_number = 12345;			//�s�񥿽T���K�X
	int match_num_pin = 0;			//�s��user��J��NUM���ഫ�L�᪺PIN��
	int input_num;
	int NUM[10] = { 0 };			//�s��1~3�������H���𪺰}�C�Ŷ�
	
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		NUM[i] = (rand() % 3) + 1;
		cout << NUM[i] << " ";
	}

	//Ū�J�ϥΪ̿�J��NUM��
	cout << endl;
	cout << "\nEnter response(1~3): ";
	cin >> input_num;

	int power = 0;
	while (pin_number > 0) {
		//�NPIN������NUM�ȡA��@�@�Ӿ�Ƴ]��match_num_pin
		match_num_pin = match_num_pin + (int)(NUM[pin_number % 10] * pow(10, power));
		pin_number = pin_number / 10;
		power++;
	}
	//�P�_�ϥΪ̿�J��NUM�O�_�PPIN�ȧk�X
	if (input_num == match_num_pin) {
		cout << "login success!" << endl;
	}
	else cout << "login fail!" << endl;

	system("pause");
	return 0;
}