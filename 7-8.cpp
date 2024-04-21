//輸出成績柱狀圖
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int find_max(vector<int> grades);

int main(void) {
	vector<int> grades;				//紀錄輸入的成績
	vector<int> histogram;			//紀錄個別成績的數量
	int stdgrade;
	int maxgrade;

	cout << "Enter greads until enter -1: ";
	while (true) {
		cin >> stdgrade;
		grades.push_back(stdgrade);
		if (stdgrade == -1) {
			break;
		}
	}
	//找出最高分成績
	maxgrade = find_max(grades);					
	//因為柱狀圖的座標包含最小值到最大值的所有分數，將histogram的長度設為成績最大值加一，並初始化所有數字為0，用resize()
	histogram.resize(maxgrade + 1);					
	

	for (int i = 0; i < grades.size()-1; i++) {		//grades.size()-1為不考慮最後一個-1
		histogram[grades[i]]++;						//統計每個分數各有多少個(將當前紀錄成績數量加一)
	}

	//印出橫向柱狀圖
	cout << "Histogram of Grades:" << endl;
	for (int j = 0; j < histogram.size(); j++) {	//顯示出分數的範圍(從0到最高分成績)
		cout << "grade of " << j << " : ";
		for (int k = 0; k < histogram[j]; k++) {	//該分數有幾個就印出幾個*(histogram[j]記錄在第j格，j分的數量)
			cout << "*" << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
int find_max(vector<int> grades) {
	int max_grade = 0;
	for (int i = 1; i < grades.size(); i++) {
		if (grades.at(i) > max_grade) {
			max_grade = grades.at(i);
		}
	}
	return (max_grade);
}