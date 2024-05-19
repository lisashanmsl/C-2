#include<iostream>
#include<cstdlib>
using namespace std;

class Complex
{
public:
	Complex();								//default consturctor
	Complex(double realPart);				//consturctor
	Complex(double real, double imaginary);
	void set_real(double real) { this->real = real; }
	void set_imaginary(double imaginary) { this->imaginary = imaginary; }
	double get_real()const { return real; }
	double get_imaginary()const { return imaginary; }

	friend const Complex operator +(const Complex& c1, const Complex& c2);
	friend const Complex operator -(const Complex& c1, const Complex& c2);
	friend const Complex operator *(const Complex& c1, const Complex& c2);
	friend bool operator ==(const Complex& c1, const Complex& c2);
	friend ostream& operator <<(ostream& outputStream, const Complex& c1);
	friend istream& operator >>(istream& inputStream, Complex& c1);

private:
	double real;
	double imaginary;
};

int main(void)
{
	Complex complex1, complex2;

	cout << "Enter first complex number: ";
	cin >> complex1;	//operator>>(cin,complex1)
	cout << "Enter second complex number: ";
	cin >> complex2;	//operator>>(cin,complex2)

	cout << "complex1 + complex2 = " << complex1 + complex2 << endl;
	cout << "complex1 - complex2 = " << complex1 - complex2 << endl;
	cout << "complex1 * complex2 = " << complex1 * complex2 << endl;

	if (complex1 == complex2) {
		cout << "Same complex number." << endl;
	}
	else {
		cout << "Different complex number" << endl;
	}

	system("pause");
	return 0;
}

Complex::Complex() :real(0), imaginary(0) {}
Complex::Complex(double realPart) :real(realPart), imaginary(0) {}
Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

const Complex operator +(const Complex& c1, const Complex& c2) {
	double real, imaginary;

	real = c1.real + c2.real;
	imaginary = c1.imaginary + c2.imaginary;

	return Complex(real, imaginary);//回傳物件
}

const Complex operator -(const Complex& c1, const Complex& c2) {
	double real, imaginary;

	real = c1.real - c2.real;
	imaginary = c1.imaginary - c2.imaginary;

	return Complex(real, imaginary);//回傳物件
}

const Complex operator *(const Complex& c1, const Complex& c2) {
	double real, imaginary;

	real = (c1.real * c2.real - c1.imaginary * c2.imaginary);
	imaginary = (c1.real * c2.imaginary + c1.imaginary * c2.real);

	return Complex(real, imaginary);//回傳物件
}

bool operator ==(const Complex& c1, const Complex& c2) {
	//各自比較實部及虛部
	return (c1.get_real() == c2.get_real() && c1.get_imaginary() == c2.get_imaginary());
}

ostream& operator <<(ostream& outputStream, const Complex& c1) {
	if (c1.imaginary >= 0) {
		outputStream << c1.real << '+' << c1.imaginary << 'i' << endl;
	}
	else {
		outputStream << c1.real << '-' << fabs(c1.imaginary) << 'i' << endl;
	}
	return outputStream;//回傳指標
}

istream& operator >>(istream& inputStream, Complex& c1) {

	inputStream >> c1.real >> c1.imaginary;
	return inputStream;//回傳指標
}