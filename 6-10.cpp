//創建Weight物件並測試
#include<iostream>
#include<cstdlib>
using namespace std;

class Weight {
public:
	Weight();			//預設建構子

	void setWeightPound(double pud) {
		pounds = pud;
	}
	void setWeightKilogram(double kg) {
		pounds = kg * 2.21;
	}
	void setWeightOunces(double oz) {
		pounds = oz / 16;
	}
	double getWeightPound() const {
		return pounds;
	}
	double getWeightKilogram() const {
		return pounds / 2.21;
	}
	double getWeightOunces() const {
		return pounds * 16;
	}

private:
	double pounds;
};

int main(void) {

	Weight weight1;

	weight1.setWeightPound(10);
	cout << "Weight in pound: " << weight1.getWeightPound() << endl;
	cout << "Weight in kilogram: " << weight1.getWeightKilogram() << endl;
	cout << "Weight in ounce: " << weight1.getWeightOunces() << endl;
	
	weight1.setWeightKilogram(10);
	cout << "Weight in pound: " << weight1.getWeightPound() << endl;
	cout << "Weight in kilogram: " << weight1.getWeightKilogram() << endl;
	cout << "Weight in ounce: " << weight1.getWeightOunces() << endl;
	
	weight1.setWeightOunces(10);
	cout << "Weight in pound: " << weight1.getWeightPound() << endl;
	cout << "Weight in kilogram: " << weight1.getWeightKilogram() << endl;
	cout << "Weight in ounce: " << weight1.getWeightOunces() << endl;


	system("pause");
	return 0;
}
Weight::Weight() :pounds(0.0){}