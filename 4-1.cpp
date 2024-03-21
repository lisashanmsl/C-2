//24小時制轉12小時制
#include<iostream>
using namespace std;

void inputTime(int& hour, int& minute);
void convertTime(int& hour, int& minute, char& period);
void outputTime(int hour, int minute, char period);
void convertAgain(char& choise);

int main(void)
{
	int hour, minute;
	char period;
	char choise;

	do {
		inputTime(hour, minute);
		convertTime(hour, minute, period);
		outputTime(hour, minute, period);
		convertAgain(choise);
	} while (choise == 'y' || choise == 'Y');

	system("pause");
	return 0;
}
void inputTime(int& hour, int& minute) {
	cout << "Enter hour and minute in 24-hour notation: ";
	cin >> hour >> minute;
}
void convertTime(int& hour, int& minute, char& period) {
	if (hour < 12) {
		period = 'A';
		if (hour == 0) {
			hour = 12;
		}
	}
	else if (hour >= 12) {
		period = 'P';
		if (hour > 12) {
			hour = hour - 12;
		}
	}
}
void outputTime(int hour, int minute, char period) {
	cout << "After converts from 24-hour notation to 12-hour notation: " << endl;
	cout << hour << " : " << minute << " " << period << ".M." << endl;
}
void convertAgain(char& choise) {
	cout << "Convert again or not?(y/n): ";
	cin >> choise;
}