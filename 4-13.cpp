//overload function of mile per hour
#include<iostream>
using namespace std;

//��Ӥ��P�������p��mph��function		
double convertToMPH(int minute, int second);		//Ū�J�t�t�X���X��A�ഫ���C�p�ɴX�^��
double convertToMPH(double kph);					//Ū�J�C�p�ɴX�����A�ഫ���C�p�ɴX�^��(kph/1.61)

int main(void)
{
	int minute, second;	
	double kph;
	char choise;

	do {
		//Ū�J�t�t�X���X��
		cout << "Enter minutes and seconds for pace in mph: ";
		cin >> minute >> second;
		cout << "MPH: " << convertToMPH(minute, second) << endl;

		//Ū�J�C�p�ɴX����
		cout << "Enter kph to convert: ";
		cin >> kph;
		cout << "MPH: " << convertToMPH(kph) << endl;

		cout << "Test again?(y/n): ";
		cin >> choise;
	} while (choise == 'y' || choise == 'Y');
	
	return 0;
}
double convertToMPH(int minute, int second) {
	double total_minute = minute + (second / 60.0);
	return(60.0 / total_minute);
}
double convertToMPH(double kph) {
	return(kph / 1.61);
}