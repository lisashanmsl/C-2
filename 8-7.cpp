//創建prime number類別，並多載operator++ --的功能
#include<iostream>
#include<cstdlib>
using namespace std;

class PrimeNumber
{
public:
	PrimeNumber();
	PrimeNumber(int num);
	void set_prime(int num) { this->prime = num; }
	int get_prime()const { return prime; }

	//多載operator讓operator有其他功能
	friend const PrimeNumber operator ++(PrimeNumber& num1);	//定義postfix++
	friend const PrimeNumber operator --(PrimeNumber& num1);	//定義postfix--

private:
	int prime;
	bool isPrime(int num)const;			//判斷是否為質數
	int findNextPrime(int num);			//找比當前質數還大的下一個質數
	int findPreviousPrime(int num);		//找比當前質數還小的下一個質數
};

int main(void)
{
	PrimeNumber prime1(5), prime2(11);			//creat two objects

	cout << "Current number: " << prime1.get_prime() << endl;
	
	//測試多載後operator(++)對物件的功能	
	++prime1;			
	cout << "Next prime number: " << prime1.get_prime() << endl;


	cout << "Current number: " << prime2.get_prime() << endl;
	
	//測試多載後operator(--)對物件的功能
	--prime2;				
	cout << "Previous prime number: " << prime2.get_prime() << endl;

	return 0;
}
PrimeNumber::PrimeNumber() :prime(1) {}
PrimeNumber::PrimeNumber(int num) {
	this->prime = num;
}

//判斷是否為質數
bool PrimeNumber::isPrime(int num)const {
	if (num <= 1) {
		return false;
	}
	else {
		for (int i = 2; i*i < num; i++) {
			if (num % i == 0) {		//在2到自身數字之間有數字可以整除自己，則回傳false
				return false;
			}
		}
	}
	return true;	
}
//搜尋在自身之後的質數
int PrimeNumber::findNextPrime(int num) {
	while (!isPrime(num)) {
		num++;
	}
	return num;
}
//搜尋在自身之前的質數
int PrimeNumber::findPreviousPrime(int num) {
	while (!isPrime(num)) {
		num--;
	}
	return num;
}
const PrimeNumber operator ++(PrimeNumber& num1) {
	num1.prime = num1.findNextPrime(num1.prime + 1);	//傳入自身數字加一，搜尋下一個質數
	return num1;
}
const PrimeNumber operator --(PrimeNumber& num1) {		//傳入自身數字減一，搜尋前一個質數
	num1.prime = num1.findPreviousPrime(num1.prime - 1);
	return num1;			//回傳物件的reference
}