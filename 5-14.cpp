#include<iostream>
#include<cmath>
using namespace std;

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size);
int min_distance(const double list[], int size);

int main(void) 
{
	int user_reviews[3] = { 0 };
	int movie_number[3] = { 0 };
	int reviews[4][6] =
	{
		{3,1,5,2,1,5},
		{4,2,1,4,2,4},
		{3,1,2,4,4,1},
		{5,1,4,2,4,2}
	};

	cout << "Enter the movies number and your rate: ";
	for (int i = 0; i < 3; i++) {
		cin >> movie_number[i] >> user_reviews[i];
		movie_number[i] = movie_number[i] - 100;
	}

	int reviewer = cartesian_distance(reviews, user_reviews, movie_number, 3);
	cout << "Reviewer " << reviewer << "'s ratings is most closely match the ratings input by the user." << endl;
	cout << "We predict the user's interest in the other movies. " << endl;

	for (int j = 0; j < 6; j++) {
		if (j != movie_number[0]&& j != movie_number[1]&& j != movie_number[2]) {
			cout << "Rating of " << reviews[reviewer][j] << " for movie " << 100 + j << endl;
		}
	}
	return 0;
}

int cartesian_distance(int list1[][6], int list2[], int movie_number[], int size) {
	double sqroot[4] = { 0 };
	int min_distance_index = 0;

	for (int i = 0; i < size; i++) {
		double distance = 0.0;
		for (int j = 0; j < size+1; j++) {
			distance = distance + pow((list2[movie_number[i]] - list1[j][movie_number[i]]), 2);
		}
		sqroot[i] = sqrt(distance);			//將與每位評論家的評分與使用者的評分相減平方相加之後的結果開根號(依序紀錄0,1,2,3位評論家)
	}
	min_distance_index = min_distance(sqroot, size);	//找到開根號的值最小的評論家
	return(min_distance_index);
}

int min_distance(const double list[], int size) {
	int min = 0;
	for (int i = 1; i < size + 1; i++) {
		if (list[i] < list[min]) {
			min = i;
		}
	}
	return(min);
}