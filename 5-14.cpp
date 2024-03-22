#include<iostream>
#include<cmath>
using namespace std;

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size);
int min_distance(const double list[], int size);

int main(void) 
{
	int user_reviews[3] = { 0 };		//存放讀入的使用者評分
	int movie_number[3] = { 0 };		//存放讀入的電影編號
	int reviews[4][6] =					//比照四個評論家對六部電影(100~105)的個別評分
	{
		{3,1,5,2,1,5},
		{4,2,1,4,2,4},
		{3,1,2,4,4,1},
		{5,1,4,2,4,2}
	};

	cout << "Enter the movies number and your rate: ";
	for (int i = 0; i < 3; i++) {
		cin >> user_reviews[i] >> movie_number[i];		//讀入評分及電影編號
		movie_number[i] = movie_number[i] - 100;		//用每部電影編號的個位數字做表示
	}

	int reviewer = cartesian_distance(reviews, user_reviews, movie_number, 3);	//將與使用者評分最相近的評論家編號設給變數reviewer
	cout << "\nReviewer " << reviewer << "'s ratings is most closely match the ratings input by the user." << endl;
	cout << "We predict the user's interest in the other movies. \n" << endl;

	//印出該位評論家對其他電影給出的分數
	for (int j = 0; j < 6; j++) {
		//不包含使用者輸入的
		if (j != movie_number[0]&& j != movie_number[1]&& j != movie_number[2]) {
			cout << "Rating of " << reviews[reviewer][j] << " for movie " << 100 + j << endl;
		}
	}
	return 0;
}

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size) {
	double sqroot[4] = { 0 };			//存放開根號之後的結果(依序對應0~3四位評論家)
	int min_distance_index = 0;			//紀錄sqroot陣列中最小值所在的索引值

	for (int i = 0; i < size+1; i++) {
		double distance = 0.0;
		//每跑完一次裡面的迴圈，表示計算了與第一個評論家之間的cartesian_distance
		for (int j = 0; j < size; j++) {
			distance = distance + pow((list2[j] - list1[i][movie_number[j]]), 2);
			sqroot[i] = sqrt(distance);			//將與每位評論家的評分與使用者的評分相減平方相加之後的結果開根號(依序紀錄0,1,2,3位評論家)
		}
	}
	min_distance_index = min_distance(sqroot, size);	//找到開根號的值最小的評論家
	return(min_distance_index);							//回傳陣列中最小值所在的索引值(也就是與使用者評分最相近的評論家編號)
}

int min_distance(const double list[], int size) {
	int min = 0;

	//在一個陣列中找到小值所在的索引值
	for (int i = 1; i < size + 1; i++) {
		if (list[i] < list[min]) {
			min = i;
		}
	}
	return(min);	//回傳陣列中最小值所在的索引值
}