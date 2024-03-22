//紀錄n個學生的成績各有多少
#include<iostream>
using namespace std;
const int SIZE = 1000;

void fill_gradeTOarray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);

int main(void)
{
	int numberUsed;					//真正使用的陣列格數(陣列長度)
	int grade[6] = { 0 };			//小考分數的範圍0~5，先初始化為0
	int student_grade[SIZE];		//儲存使用者輸入的成績個數

	//紀錄真正使用的陣列格數
	fill_gradeTOarray(student_grade, SIZE, numberUsed);

	//印出0~5的成績各有多少人
	int stdent_number;
	for (int i = 0; i < 6; i++) {
		stdent_number = search(student_grade, numberUsed, i);
		cout << stdent_number << " grade(s) of " << i << endl;
	}

	return 0;
}
void fill_gradeTOarray(int a[], int size, int& numberUsed) {
	int grade;
	int index = 0;

	//輸入學生成績(0~5)直到輸入一個負數停止讀取
	cout << "Enter number of student grade(0~5), stop enter by input -1: ";
	cin >> grade;

	while ((grade >= 0) && (index < SIZE)) {
		a[index] = grade;		//將讀入的成績存到陣列中
		index++;				//更新索引值加一
		cin >> grade;			//在讀下一個成績
	}
	cout << "\n";
	numberUsed = index + 1;		//紀錄真正使用到的陣列長度
}
int search(const int a[], int numberUsed, int target) {
	int count = 0;		//count用來記錄0~5分各有多少人
	for (int i = 0; i < numberUsed; i++) {
		//比較陣列中相同的分數，再用count紀錄有幾個相同的分數
		if (a[i] == target) {
			count++;
		}
	}
	return(count);		//回傳當前分數的總人數
}