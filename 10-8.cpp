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
	string displayType;				//�q������
	double dimension;				//�ؤo
	string* connectivitySupport;	//�ʺA�}�C
	int connectivitySize;			//�}�C�j�p
};
int main(void)
{
	string defaultType;
	double defaultDimension;
	int defaultConnSize;
	string* defaultConnSup;

	//Ū�J�w�]��
	cout << "Enter default type: ";
	cin >> defaultType;
	cout << "Enter default dimension: ";
	cin >> defaultDimension;
	cout << "Enter number of support of connectivity modes: ";
	cin >> defaultConnSize;

	//new�@�ӪŶ��Ӧs��w�]��
	defaultConnSup = new string[defaultConnSize];
	for (int i = 0; i < defaultConnSize; i++) {
		cout << "Enter connectivity mode" << i + 1 << " : ";
		cin >> defaultConnSup[i];
	}
	/*�ǥѨϥΪ̿�J����ƨӫإ�Television���w�]����*/
	Television defaultTV(defaultType, defaultDimension, defaultConnSup, defaultConnSize);

	int numTV;
	cout << "Enter number of Television: ";
	cin >> numTV;

	/*��Television���O���ʺA�}�C�Ыئh��Television����*/
	Television* tvArray = new Television[numTV];
	for (int j = 0; j < numTV; j++) {
		tvArray[j] = defaultTV;
	}

	//�P�_�ϥΪ̬O�_�ݭn�Ȼs��
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

			//new�@�ӪŶ��Ӧs��Ȼs�Ƥ��e
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

	delete[] defaultConnSup;	//�k�٪Ŷ�
	delete[] tvArray;			//�k�٪Ŷ�

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
//�ƻs�غc�l
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
//�h��=
Television& Television::operator=(const Television& rightSide)
{
	//�P�_�O�_�����@�˪�����
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