#include<iostream>
#include<string>
using namespace std;

class Television
{
public:
	Television();
	Television(string& Type, double dimension, string* connect, int connect_size);
	Television(const Television& Object);				//copy consturctor

	void set_displayType(string& Type) { displayType = Type; }
	void set_dimension(double dimension) { this->dimension = dimension; }
	void set_connectivitySupport(string* connect, int connect_size);
	string get_displayType()const { return displayType; }
	double get_dimension()const { return dimension; }
	int get_connectivitySize()const { return connectivitySize; }
	string* get_connectivitySupport()const { return connectivitySupport; }

	Television& operator =(const Television& rightSide);
	~Television();		//desturctor

private:
	string displayType;				//電視類型
	double dimension;				//尺寸
	string* connectivitySupport;	//動態陣列
	int connectivitySize;			//陣列大小
};
int main(void)
{
	string defaultType;
	double defaultDimension;
	int defaultConnSize;
	string* defaultConnSup;

	//讀入預設值
	cout << "Enter default type: ";
	cin >> defaultType;
	cout << "Enter default dimension: ";
	cin >> defaultDimension;
	cout << "Enter number of support of connectivity modes: ";
	cin >> defaultConnSize;

	//new一個空間來存放預設值
	defaultConnSup = new string[defaultConnSize];
	for (int i = 0; i < defaultConnSize; i++) {
		cout << "Enter connectivity mode" << i + 1 << " : ";
		cin >> defaultConnSup[i];
	}
	/*藉由使用者輸入的資料來建立Television的預設物件*/
	Television defaultTV(defaultType, defaultDimension, defaultConnSup, defaultConnSize);

	int numTV;
	cout << "Enter number of Television: ";
	cin >> numTV;

	/*用Television類別的動態陣列創建多個Television物件*/
	Television* tvArray = new Television[numTV];
	for (int j = 0; j < numTV; j++) {
		tvArray[j] = defaultTV;
	}

	//判斷使用者是否需要客製化
	char customize;
	for (int k = 0; k < numTV; k++) {
		cout << "Customize TV" << k + 1 << " (y/n): ";
		cin >> customize;
		if (customize == 'y' || customize == 'Y') {
			string type;
			double dim;
			int connSize;
			string* connSup;
			
			cout << "Enter the type you want: ";
			cin >> type;
			cout << "Enter the dimension you want: ";
			cin >> dim;
			cout << "Enter number of support of connectivity modes: ";
			cin >> connSize;

			//new一個空間來存放客製化內容
			connSup = new string[connSize];
			for (int l = 0; l < connSize; l++) {
				cout << "Enter connectivity mode" << l + 1 << " : ";
				cin >> connSup[l];
			}

			tvArray[k].set_displayType(type);
			tvArray[k].set_dimension(dim);
			tvArray[k].set_connectivitySupport(connSup, connSize);

			delete[] connSup;
		}
	}

	delete[] defaultConnSup;	//歸還空間
	delete[] tvArray;			//歸還空間

	system("pause");
	return 0;
}
Television::Television() :displayType(" "), dimension(0.0), connectivitySize(0), connectivitySupport(nullptr){}
Television::Television(string& Type, double dimension, string* connect, int connect_size)
{
	displayType = Type;
	this->dimension = dimension;
	connectivitySize = connect_size;

	connectivitySupport = new string[connectivitySize];
	for (int i = 0; i < connectivitySize; i++) {
		connectivitySupport[i] = connect[i];
	}
}
//複製建構子
Television::Television(const Television& Object)
{
	displayType = Object.get_displayType();
	this->dimension = Object.get_dimension();
	connectivitySize = Object.get_connectivitySize();

	connectivitySupport = new string[connectivitySize];
	for (int i = 0; i < connectivitySize; i++) {
		connectivitySupport[i] = Object.connectivitySupport[i];
	}
}
//多載=
Television& Television::operator=(const Television& rightSide)
{
	//判斷是否為不一樣的物件
	if (this != &rightSide) {
		delete[] connectivitySupport;
		
		displayType = rightSide.get_displayType();
		this->dimension = rightSide.get_dimension();
		connectivitySize = rightSide.get_connectivitySize();

		connectivitySupport = new string[connectivitySize];
		for (int i = 0; i < connectivitySize; i++) {
			connectivitySupport[i] = rightSide.connectivitySupport[i];
		}
		return *this;
	}
}
void Television::set_connectivitySupport(string* connect, int connect_size)
{
	delete[] connectivitySupport;
	connectivitySize = connect_size;
	connectivitySupport = new string[connectivitySize];
	for (int i = 0; i < connectivitySize; i++) {
		connectivitySupport[i] = connect[i];
	}
}
Television::~Television()
{
	delete[] connectivitySupport;
}