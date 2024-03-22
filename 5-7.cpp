//����n�Ӿǥͪ����Z�U���h��
#include<iostream>
using namespace std;
const int SIZE = 1000;

void fill_gradeTOarray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);

int main(void)
{
	int numberUsed;					//�u���ϥΪ��}�C���(�}�C����)
	int grade[6] = { 0 };			//�p�Ҥ��ƪ��d��0~5�A����l�Ƭ�0
	int student_grade[SIZE];		//�x�s�ϥΪ̿�J�����Z�Ӽ�

	//�����u���ϥΪ��}�C���
	fill_gradeTOarray(student_grade, SIZE, numberUsed);

	//�L�X0~5�����Z�U���h�֤H
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

	//��J�ǥͦ��Z(0~5)�����J�@�ӭt�ư���Ū��
	cout << "Enter number of student grade(0~5), stop enter by input -1: ";
	cin >> grade;

	while ((grade >= 0) && (index < SIZE)) {
		a[index] = grade;		//�NŪ�J�����Z�s��}�C��
		index++;				//��s���ޭȥ[�@
		cin >> grade;			//�bŪ�U�@�Ӧ��Z
	}
	cout << "\n";
	numberUsed = index + 1;		//�����u���ϥΨ쪺�}�C����
}
int search(const int a[], int numberUsed, int target) {
	int count = 0;		//count�ΨӰO��0~5���U���h�֤H
	for (int i = 0; i < numberUsed; i++) {
		//����}�C���ۦP�����ơA�A��count�������X�ӬۦP������
		if (a[i] == target) {
			count++;
		}
	}
	return(count);		//�^�Ƿ�e���ƪ��`�H��
}