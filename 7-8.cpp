//��X���Z�W����
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int find_max(vector<int> grades);

int main(void) {
	vector<int> grades;				//������J�����Z
	vector<int> histogram;			//�����ӧO���Z���ƶq
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
	//��X�̰������Z
	maxgrade = find_max(grades);					
	//�]���W���Ϫ��y�Х]�t�̤p�Ȩ�̤j�Ȫ��Ҧ����ơA�Nhistogram�����׳]�����Z�̤j�ȥ[�@�A�ê�l�ƩҦ��Ʀr��0�A��resize()
	histogram.resize(maxgrade + 1);					
	

	for (int i = 0; i < grades.size()-1; i++) {		//grades.size()-1�����Ҽ{�̫�@��-1
		histogram[grades[i]]++;						//�έp�C�Ӥ��ƦU���h�֭�(�N��e�������Z�ƶq�[�@)
	}

	//�L�X��V�W����
	cout << "Histogram of Grades:" << endl;
	for (int j = 0; j < histogram.size(); j++) {	//��ܥX���ƪ��d��(�q0��̰������Z)
		cout << "grade of " << j << " : ";
		for (int k = 0; k < histogram[j]; k++) {	//�Ӥ��Ʀ��X�ӴN�L�X�X��*(histogram[j]�O���b��j��Aj�����ƶq)
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