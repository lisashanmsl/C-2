//�s�X�θѽX
#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

class ZipCode {
public:
	ZipCode();
	ZipCode(int zipcode);			
	ZipCode(string barcode);	
	void set_zipcode(int zipcode) { this->zipcode = zipcode; }
	void set_barcode(string barcode) { barcodeTozip(barcode); }
	int get_zipcode()const { return zipcode; }
	string get_barcode() { return zipTobarcode(zipcode); }

private:
	int zipcode;
	string zipTobarcode(int zipcode);		//�ഫ�\�઺��Ʃ�bprivate��
	int barcodeTozip(string barcode);
};

int main(void) {

	ZipCode zip1(97504);								//�Ыت���A�ǤJ��ƫ��A����
	cout << "Zipcode: " << zip1.get_zipcode() << endl;
	cout << "Barcode: " << zip1.get_barcode() << endl;
	cout << endl;

	ZipCode zip2("110100101000101011000010011");		//�Ыت���A�ǤJ�r�ꫬ�A����
	cout << "Zipcode: " << zip2.get_zipcode() << endl;
	cout << "Barcode: " << zip2.get_barcode() << endl;

	system("pause");
	return 0;
}
ZipCode::ZipCode() :zipcode(){}					//defalt consturctor
ZipCode::ZipCode(int zipcode) {					//�ǤJ���zipcode
	this->zipcode = zipcode;					//��l��zipcode
}
ZipCode::ZipCode(string barcode) {
	this->zipcode = barcodeTozip(barcode);
}
string ZipCode::zipTobarcode(int zipcode) {		//�qzipcode�ରbarcode
	int digit;
	string group;
	string barcode = "1";
	for (int i = 4; i >= 0; i--) {					//�q����Ĥ@��ƶ}�l�P�_
		digit = (zipcode / (int)pow(10, i)) % 10;	//�ѥ��ܥk�P�_���P��ƩҥN��group
		switch (digit) {
		case 0:
			group = "11000";
			break;
		case 1:
			group = "00011";
			break;
		case 2:
			group = "00101";
			break;
		case 3:
			group = "00110";
			break;
		case 4:
			group = "01001";
			break;
		case 5:
			group = "01010";
			break;
		case 6:
			group = "01100";
			break;
		case 7:
			group = "10001";
			break;
		case 8:
			group = "10010";
			break;
		case 9:
			group = "10100";
			break;
		default:
			cout << "Input invalid." << endl;
			break;
		}
		barcode = barcode + group;		//�N�C����group�ꦨ�@��
	}
	return(barcode + "1");				//�^��barcode
}
int ZipCode::barcodeTozip(string barcode) {		//�qbarcode�ରzipcode
	int digit = 0;								
	int zipcode = 0;			
	for (int i = 1; i < 22; i = i + 5) {		//����barcode�Ĥ@�Ӧr���A�C���խp��@��zipcode digit
		//��h�Ʀr0��ASCII code�A�C�Ӧ�ƦA���O���W7 4 2 1 0
		digit = (barcode[i] - '0') * 7 + (barcode[i + 1] - '0') * 4 + (barcode[i + 2] - '0') * 2 + (barcode[i + 3] - '0') * 1;
		if (digit == 11) {
			digit = 0;
		}
		zipcode = zipcode * 10 + digit;
	}
	return(zipcode);
}