#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int find_max(vector<int> grades);

int main(void) {
	vector<int> grades;
	vector<int> histogram;
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
	//т程蔼だΘ罿
	maxgrade = find_max(grades);					
	//琖瓜畒夹程程┮Τだ计盢histogram砞Θ罿程﹍て┮Τ计0ノresize()
	histogram.resize(maxgrade + 1);					


	for (int i = 0; i < grades.size()-1; i++) {		//grades.size()-1ぃσ納程-1
		histogram[grades[i]]++;						//参璸–だ计Τぶ(盢讽玡魁Θ罿计秖)
	}

	//绢琖瓜
	cout << "Histogram of Grades:" << endl;
	for (int j = 0; j < histogram.size(); j++) {	//陪ボだ计絛瞅(眖0程蔼だΘ罿)
		cout << "grade of " << j << " : ";
		for (int k = 0; k < histogram[j]; k++) {	//赣だ计Τ碭碞碭*(histogram[j]癘魁材jjだ计秖)
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