//編碼及解碼
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
	string zipTobarcode(int zipcode);		//轉換功能的函數放在private中
	int barcodeTozip(string barcode);
};

int main(void) {

	ZipCode zip1(97504);								//創建物件，傳入整數型態測試
	cout << "Zipcode: " << zip1.get_zipcode() << endl;
	cout << "Barcode: " << zip1.get_barcode() << endl;
	cout << endl;

	ZipCode zip2("110100101000101011000010011");		//創建物件，傳入字串型態測試
	cout << "Zipcode: " << zip2.get_zipcode() << endl;
	cout << "Barcode: " << zip2.get_barcode() << endl;

	system("pause");
	return 0;
}
ZipCode::ZipCode() :zipcode(){}					//defalt consturctor
ZipCode::ZipCode(int zipcode) {					//傳入整數zipcode
	this->zipcode = zipcode;					//初始化zipcode
}
ZipCode::ZipCode(string barcode) {
	this->zipcode = barcodeTozip(barcode);
}
string ZipCode::zipTobarcode(int zipcode) {		//從zipcode轉為barcode
	int digit;
	string group;
	string barcode = "1";
	for (int i = 4; i >= 0; i--) {					//從左邊第一位數開始判斷
		digit = (zipcode / (int)pow(10, i)) % 10;	//由左至右判斷不同位數所代表的group
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
		barcode = barcode + group;		//將每五個group串成一個
	}
	return(barcode + "1");				//回傳barcode
}
int ZipCode::barcodeTozip(string barcode) {		//從barcode轉為zipcode
	int digit = 0;								
	int zipcode = 0;			
	for (int i = 1; i < 22; i = i + 5) {		//扣除barcode第一個字元，每五組計算一次zipcode digit
		//減去數字0的ASCII code，每個位數再分別乘上7 4 2 1 0
		digit = (barcode[i] - '0') * 7 + (barcode[i + 1] - '0') * 4 + (barcode[i + 2] - '0') * 2 + (barcode[i + 3] - '0') * 1;
		if (digit == 11) {
			digit = 0;
		}
		zipcode = zipcode * 10 + digit;
	}
	return(zipcode);
}