#include<iostream>
#include<cmath>
using namespace std;

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size);
int min_distance(const double list[], int size);

int main(void) 
{
	int user_reviews[3] = { 0 };		//�s��Ū�J���ϥΪ̵���
	int movie_number[3] = { 0 };		//�s��Ū�J���q�v�s��
	int reviews[4][6] =					//��ӥ|�ӵ��׮a�碌���q�v(100~105)���ӧO����
	{
		{3,1,5,2,1,5},
		{4,2,1,4,2,4},
		{3,1,2,4,4,1},
		{5,1,4,2,4,2}
	};

	cout << "Enter the movies number and your rate: ";
	for (int i = 0; i < 3; i++) {
		cin >> user_reviews[i] >> movie_number[i];		//Ū�J�����ιq�v�s��
		movie_number[i] = movie_number[i] - 100;		//�ΨC���q�v�s�����Ӧ�Ʀr�����
	}

	int reviewer = cartesian_distance(reviews, user_reviews, movie_number, 3);	//�N�P�ϥΪ̵����̬۪񪺵��׮a�s���]���ܼ�reviewer
	cout << "\nReviewer " << reviewer << "'s ratings is most closely match the ratings input by the user." << endl;
	cout << "We predict the user's interest in the other movies. \n" << endl;

	//�L�X�Ӧ���׮a���L�q�v���X������
	for (int j = 0; j < 6; j++) {
		//���]�t�ϥΪ̿�J��
		if (j != movie_number[0]&& j != movie_number[1]&& j != movie_number[2]) {
			cout << "Rating of " << reviews[reviewer][j] << " for movie " << 100 + j << endl;
		}
	}
	return 0;
}

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size) {
	double sqroot[4] = { 0 };			//�s��}�ڸ����᪺���G(�̧ǹ���0~3�|����׮a)
	int min_distance_index = 0;			//����sqroot�}�C���̤p�ȩҦb�����ޭ�

	for (int i = 0; i < size+1; i++) {
		double distance = 0.0;
		//�C�]���@���̭����j��A��ܭp��F�P�Ĥ@�ӵ��׮a������cartesian_distance
		for (int j = 0; j < size; j++) {
			distance = distance + pow((list2[j] - list1[i][movie_number[j]]), 2);
			sqroot[i] = sqrt(distance);			//�N�P�C����׮a�������P�ϥΪ̪������۴��ۥ[���᪺���G�}�ڸ�(�̧Ǭ���0,1,2,3����׮a)
		}
	}
	min_distance_index = min_distance(sqroot, size);	//���}�ڸ����ȳ̤p�����׮a
	return(min_distance_index);							//�^�ǰ}�C���̤p�ȩҦb�����ޭ�(�]�N�O�P�ϥΪ̵����̬۪񪺵��׮a�s��)
}

int min_distance(const double list[], int size) {
	int min = 0;

	//�b�@�Ӱ}�C�����p�ȩҦb�����ޭ�
	for (int i = 1; i < size + 1; i++) {
		if (list[i] < list[min]) {
			min = i;
		}
	}
	return(min);	//�^�ǰ}�C���̤p�ȩҦb�����ޭ�
}