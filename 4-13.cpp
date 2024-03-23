//overload function of mile per hour
#include<iostream>
using namespace std;

//兩個不同版本的計算mph的function		
double convertToMPH(int minute, int second);		//讀入配速幾分幾秒，轉換為每小時幾英哩
double convertToMPH(double kph);					//讀入每小時幾公里，轉換為每小時幾英哩(kph/1.61)

int main(void)
{
	int minute, second;	
	double kph;
	char choise;

	do {
		//讀入配速幾分幾秒
		cout << "Enter minutes and seconds for pace in mph: ";
		cin >> minute >> second;
		cout << "MPH: " << convertToMPH(minute, second) << endl;

		//讀入每小時幾公里
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