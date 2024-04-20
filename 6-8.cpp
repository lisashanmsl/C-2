//創建Money物件並測試
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Money {
public:
	Money(int dollars, int cents);			//初始化private屬性成員的建構子
	Money();								//預設建構子

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
	
	//計算真實金額
	double countMoney() {
		return (dollars + cents / 100.0);
	}

private:
	int dollars;
	int cents;
};

int main(void)
{
	Money money1(10, 50);				//用建構子創建Money物件，傳入dollars和cents的個數
	Money money2;						//預設建構子
	
	cout << "Total money: " << money1.countMoney() << "$" << endl;
	cout << "Total money: " << money2.countMoney() << "$" << endl;

	system("pause");
	return 0;
}
Money::Money(int dollars, int cents) {
	this->dollars = dollars;				//初始化成員屬性
	this->cents = cents;
}
Money::Money() :dollars(0),cents(0){}		//預設值為零