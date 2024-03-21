//����n�Ӿǥͪ����Z�U���h��
#include<iostream>
using namespace std;
const int SIZE = 1000;

void fill_gradeTOarray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);

int main(void)
{
	int numberUsed;					//�u���ϥΪ��}�C���
	int grade[6] = { 0 };			//�p�Ҥ��ƪ��d��0~5�A����l�Ƭ�0
	int student_grade[SIZE];		//�x�s�ϥΪ̿�J�����Z�Ӽ�

	fill_gradeTOarray(student_grade, SIZE, numberUsed);

	//�L�X0~5�����Z�U���h�֤H
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