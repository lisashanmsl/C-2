#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	int pin_number = 12345;			//存放正確的密碼
	int match_num_pin = 0;			//存放user輸入的NUM值轉換過後的PIN值
	int input_num;
	int NUM[10] = { 0 };			//存放1~3之間的隨機樹的陣列空間
	
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		NUM[i] = (rand() % 3) + 1;
		cout << NUM[i] << " ";
	}

	//讀入使用者輸入的NUM值
	cout << endl;
	cout << "\nEnter response(1~3): ";
	cin >> input_num;

	int power = 0;
	while (pin_number > 0) {
		//將PIN對應的NUM值，當作一個整數設給match_num_pin
		match_num_pin = match_num_pin + (int)(NUM[pin_number % 10] * pow(10, power));
		pin_number = pin_number / 10;
		power++;
	}
	//判斷使用者輸入的NUM是否與PIN值吻合
	if (input_num == match_num_pin) {
		cout << "login success!" << endl;
	}
	else cout << "login fail!" << endl;

	system("pause");
	return 0;
}