//�Ы�prime number���O�A�æh��operator++ --���\��
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

	//�h��operator��operator����L�\��
	friend const PrimeNumber operator ++(PrimeNumber& num1);	//�w�qpostfix++
	friend const PrimeNumber operator --(PrimeNumber& num1);	//�w�qpostfix--

private:
	int prime;
	bool isPrime(int num)const;			//�P�_�O�_�����
	int findNextPrime(int num);			//����e����٤j���U�@�ӽ��
	int findPreviousPrime(int num);		//����e����٤p���U�@�ӽ��
};

int main(void)
{
	PrimeNumber prime1(5), prime2(11);			//creat two objects

	cout << "Current number: " << prime1.get_prime() << endl;
	
	//���զh����operator(++)�磌�󪺥\��	
	++prime1;			
	cout << "Next prime number: " << prime1.get_prime() << endl;


	cout << "Current number: " << prime2.get_prime() << endl;
	
	//���զh����operator(--)�磌�󪺥\��
	--prime2;				
	cout << "Previous prime number: " << prime2.get_prime() << endl;

	return 0;
}
PrimeNumber::PrimeNumber() :prime(1) {}
PrimeNumber::PrimeNumber(int num) {
	this->prime = num;
}

//�P�_�O�_�����
bool PrimeNumber::isPrime(int num)const {
	if (num <= 1) {
		return false;
	}
	else {
		for (int i = 2; i*i < num; i++) {
			if (num % i == 0) {		//�b2��ۨ��Ʀr�������Ʀr�i�H�㰣�ۤv�A�h�^��false
				return false;
			}
		}
	}
	return true;	
}
//�j�M�b�ۨ����᪺���
int PrimeNumber::findNextPrime(int num) {
	while (!isPrime(num)) {
		num++;
	}
	return num;
}
//�j�M�b�ۨ����e�����
int PrimeNumber::findPreviousPrime(int num) {
	while (!isPrime(num)) {
		num--;
	}
	return num;
}
const PrimeNumber operator ++(PrimeNumber& num1) {
	num1.prime = num1.findNextPrime(num1.prime + 1);	//�ǤJ�ۨ��Ʀr�[�@�A�j�M�U�@�ӽ��
	return num1;
}
const PrimeNumber operator --(PrimeNumber& num1) {		//�ǤJ�ۨ��Ʀr��@�A�j�M�e�@�ӽ��
	num1.prime = num1.findPreviousPrime(num1.prime - 1);
	return num1;			//�^�Ǫ���reference
}