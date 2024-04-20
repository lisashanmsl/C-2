//�Ыا@�����l������
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class BoxOfProduce {
public:
	void set_produce(string p1, string p2, string p3) {
		produce[0] = p1;				//��l�@���}�C��������
		produce[1] = p2;
		produce[2] = p3;
	}
	string* get_produce() {				//�^�Ǧr��}�C���_�l��}
		return produce;
	}
	void output() {						//�L�X�c�l�����@��
		cout << "Three fruits or vegetables in the box: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << produce[i] << endl;
		}
	}
private:
	string produce[3];					//private�ݩʦ������i�s��T�Ӧr�ꪺ�r��}�C
};

int main(void) {
	srand(time(NULL));

	string produce_list[5];						//�s��q�ɮפ�Ū�J���@���W��(�r��)
	ifstream inputfile("produce_list.txt");		//�}���ɮ�
	if (!inputfile) {							//�P�_�ɮ׬O�_���`�}��
		cout << "File not found!" << endl;
		exit(1);
	}
	
	for (int i = 0; i < 5; i++) {
		inputfile >> produce_list[i];			//�q�ɮפ�Ū�J�@��
	}
	inputfile.close();

	string select_produce[3];					//�s���H���s���T�ӽ��G���}�C
	BoxOfProduce box;							//�Ыت���
	for (int j = 0; j < 3; j++) {				
		select_produce[j] = produce_list[rand() % 5];	//�q���ӽ��G���H���s���T��,���ޭȬ�0~4
	}

	box.set_produce(select_produce[0], select_produce[1], select_produce[2]);
	box.output();								//��Xbox���󤤪����e

	char choise;
	cout << "Do you want to substitute one fruit or vegetables from the produce list? (y/n)";
	cin >> choise;

	if (choise == 'y'|| choise == 'Y') {
		int index = 0;							//����諸�@�����ޭ�
		string new_produce;						//�s�@�����W��
		cout << "Enter the index that the produce you want to change (0,1,2): ";
		cin >> index;

		cout << "Enter the new produce: ";
		cin >> new_produce;
		select_produce[index] = new_produce;

		box.set_produce(select_produce[0], select_produce[1], select_produce[2]);
		cout << "Final contents of box. " << endl;
		box.output();								//��X����box���󤤪����e
	}

	system("pause");
	return 0;
}