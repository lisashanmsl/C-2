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
	
	void input_Channels();				//Ū�J�q�\�̦W�١B�q�\���W�D�ƶq
	void output_Channels()const;		//��X�q�\�̦W�١B�q�\���W�D�ƶq�B�q�\���e

	/*Overload assignment operator*/
	Subscriber& operator=(const Subscriber& rightSide);
	void resetChannels();
	~Subscriber();				//destructor

private:
	string name;				//�q�\�̦W��
	int numChannels;			//�q�\���W�D�ƶq
	string* channelList;		//�W�D�W��
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
//�ƻs�@�˪�����
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
//���m
void Subscriber::resetChannels()
{
	numChannels = 0;
	delete[] channelList;
}
//��J��T
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
//��X�W�D�ԲӸ�T
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
	//�P�_�O�_�O���@�˪�����
	if (numChannels != rightSide.numChannels) {
		delete[] channelList;		//���m�ʺA�}�C
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