//紀錄n個學生的成績各有多少
#include<iostream>
using namespace std;
const int SIZE = 1000;

void fill_gradeTOarray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);

int main(void)
{
	int numberUsed;					//真正使用的陣列格數
	int grade[6] = { 0 };			//小考分數的範圍0~5，先初始化為0
	int student_grade[SIZE];		//儲存使用者輸入的成績個數

	fill_gradeTOarray(student_grade, SIZE, numberUsed);

	//印出0~5的成績各有多少人
	int count = 0;
	for (int i = 0; i < 6; i++) {
		count = search(student_grade, numberUsed, i);
		cout << count << " grade(s) of " << i << endl;
	}

	return 0;
}
void fill_gradeTOarray(int a[], int size, int& numberUsed) {
	int grade;
	int index = 0;
	cout << "Enter number of student grade(0~5), stop enter by input -1: ";
	cin >> grade;

	while ((grade >= 0) && (index < SIZE)) {
		a[index] = grade;
		index++;
		cin >> grade;
	}
	cout << "\n";
	numberUsed = index;
}
int search(const int a[], int numberUsed, int target) {
	int count = 0;
	for (int i = 0; i < numberUsed; i++) {
		if (a[i] == target) {
			count++;
		}
	}
	return(count);
}