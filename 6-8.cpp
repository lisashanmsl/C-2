//�Ы�Money����ô���
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Money {
public:
	Money(int dollars, int cents);			//��l��private�ݩʦ������غc�l
	Money();								//�w�]�غc�l

	void set_dollars(int dollars) {
		this->dollars = dollars;
	}
	int get_dollars() const{
		return dollars;
	}
	void set_cents(int cents) {
		this->cents = cents;
	}
	int get_cents() const{
		return cents;
	}
	
	//�p��u����B
	double countMoney() {
		return (dollars + cents / 100.0);
	}

private:
	int dollars;
	int cents;
};

int main(void)
{
	Money money1(10, 50);				//�Ϋغc�l�Ы�Money����A�ǤJdollars�Mcents���Ӽ�
	Money money2;						//�w�]�غc�l
	
	cout << "Total money: " << money1.countMoney() << "$" << endl;
	cout << "Total money: " << money2.countMoney() << "$" << endl;

	system("pause");
	return 0;
}
Money::Money(int dollars, int cents) {
	this->dollars = dollars;				//��l�Ʀ����ݩ�
	this->cents = cents;
}
Money::Money() :dollars(0),cents(0){}		//�w�]�Ȭ��s