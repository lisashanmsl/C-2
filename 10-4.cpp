#include<iostream>
#include<string>
using namespace std;

class Subscriber
{
public:
	Subscriber();										//default consturctor	
	Subscriber(string& intput_name, int numChannels);	//consturctor
	Subscriber(Subscriber& Object);						//copy consturctor		

	void set_name(string& input_name) { name = input_name; }
	string get_name()const { return name; }
	void set_numchannel(int numChannels);
	int get_numchannel()const { return numChannels; }
	
	void input_Channels();				//讀入訂閱者名稱、訂閱的頻道數量
	void output_Channels()const;		//輸出訂閱者名稱、訂閱的頻道數量、訂閱內容

	/*Overload assignment operator*/
	Subscriber& operator=(const Subscriber& rightSide);
	void resetChannels();
	~Subscriber();				//destructor

private:
	string name;				//訂閱者名稱
	int numChannels;			//訂閱的頻道數量
	string* channelList;		//頻道名稱
};

int main(void)
{
	Subscriber sub1, sub2, sub3;
	sub1.input_Channels();
	sub1.output_Channels();

	sub2 = sub1;	//
	sub2.output_Channels();

	sub3 = sub1;
	sub3.output_Channels();

	sub1.resetChannels();
	sub1.output_Channels();

	system("pause");
	return 0;
}

Subscriber::Subscriber() :name(" "), numChannels(0), channelList(nullptr){}
Subscriber::Subscriber(string& intput_name, int numChannels) 
{
	name = intput_name;
	this->numChannels = numChannels;
	channelList = new string[numChannels];
}
//複製一樣的物件
Subscriber::Subscriber(Subscriber& Object)
{
	name = Object.get_name();
	numChannels = Object.get_numchannel();
	channelList = new string[numChannels];
	for (int i = 0; i < numChannels; i++) {
		channelList[i] = Object.channelList[i];
	}
}
void Subscriber::set_numchannel(int numChannels)
{
	delete[] channelList;
	this->numChannels = numChannels;
	channelList = new string[numChannels];
}
//重置
void Subscriber::resetChannels()
{
	numChannels = 0;
	delete[] channelList;
}
//輸入資訊
void Subscriber::input_Channels()
{
	cout << "Enter Subscriber's name: ";
	cin >> name;
	cout << "Enter number of channels: ";
	cin >> numChannels;

	delete[] channelList;
	channelList = new string[numChannels];
	for (int i = 0; i < numChannels; i++) {
		cout << "Enter channel " << i + 1 << " name: ";
		cin >> channelList[i];
		cout << endl;
	}
}
//輸出頻道詳細資訊
void Subscriber::output_Channels()const 
{
	cout << "Subscriber: " << name << endl;
	cout << "Channels List: " << endl;
	for (int i = 0; i < numChannels; i++) {
		cout << "-" << channelList[i] << endl;
	}
}
Subscriber& Subscriber::operator =(const Subscriber& rightSide)
{
	//判斷是否是不一樣的物件
	if (numChannels != rightSide.numChannels) {
		delete[] channelList;		//重置動態陣列
		channelList = new string[rightSide.numChannels];
	}

	name = rightSide.name;
	numChannels = rightSide.numChannels;
	for (int i = 0; i < numChannels; i++) {
		channelList[i] = rightSide.channelList[i];
	}
	return *this;
}
Subscriber::~Subscriber()
{
	delete[] channelList;
}