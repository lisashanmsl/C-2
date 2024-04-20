//創建作物盒子的物件
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class BoxOfProduce {
public:
	void set_produce(string p1, string p2, string p3) {
		produce[0] = p1;				//初始作物陣列中的元素
		produce[1] = p2;
		produce[2] = p3;
	}
	string* get_produce() {				//回傳字串陣列的起始位址
		return produce;
	}
	void output() {						//印出箱子內的作物
		cout << "Three fruits or vegetables in the box: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << produce[i] << endl;
		}
	}
private:
	string produce[3];					//private屬性成員為可存放三個字串的字串陣列
};

int main(void) {
	srand(time(NULL));

	string produce_list[5];						//存放從檔案中讀入的作物名稱(字串)
	ifstream inputfile("produce_list.txt");		//開啟檔案
	if (!inputfile) {							//判斷檔案是否正常開啟
		cout << "File not found!" << endl;
		exit(1);
	}
	
	for (int i = 0; i < 5; i++) {
		inputfile >> produce_list[i];			//從檔案中讀入作物
	}
	inputfile.close();

	string select_produce[3];					//存放隨機存取三個蔬果的陣列
	BoxOfProduce box;							//創建物件
	for (int j = 0; j < 3; j++) {				
		select_produce[j] = produce_list[rand() % 5];	//從五個蔬果中隨機存取三個,索引值為0~4
	}

	box.set_produce(select_produce[0], select_produce[1], select_produce[2]);
	box.output();								//輸出box物件中的內容

	char choise;
	cout << "Do you want to substitute one fruit or vegetables from the produce list? (y/n)";
	cin >> choise;

	if (choise == 'y'|| choise == 'Y') {
		int index = 0;							//欲更改的作物索引值
		string new_produce;						//新作物的名稱
		cout << "Enter the index that the produce you want to change (0,1,2): ";
		cin >> index;

		cout << "Enter the new produce: ";
		cin >> new_produce;
		select_produce[index] = new_produce;

		box.set_produce(select_produce[0], select_produce[1], select_produce[2]);
		cout << "Final contents of box. " << endl;
		box.output();								//輸出更改後box物件中的內容
	}

	system("pause");
	return 0;
}