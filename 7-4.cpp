#include<iostream>
#include<cstdlib>
using namespace std;

class HotDogStand {
public:
	HotDogStand();							//�w�]�غc�l
	HotDogStand(int id, int sold);			//��l��private�ݩʦ������غc�l

	void set_id(int id) {
		this->id = id;
	}
	void set_sold(int sold) {
		this->sold = sold;
	}
	int get_id() const {
		return id;
	}
	int get_sold() const {
		return sold;
	}
	void JustSold();
	static int TotalSold();

private:
	int id;
	int sold;
	static int total_sold;					//�R�A�����ݩ����O�A�Ӥ��ݩ�ӧO������A�`�ϥ����O�W�٥[�W::�Өϥ�
};

int main(void) {
	HotDogStand stand1(1, 20), stand2(2, 15), stand3(3, 10);		//�Ϋغc�l�ЫؤT��HotDogStand����A�ê�l�Ƨ���set

	cout << "The hotdog stand " << stand1.get_id() << " sells " << stand1.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand2.get_id() << " sells " << stand2.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand3.get_id() << " sells " << stand3.get_sold() << " hotdogs. " << endl;

	//�����O�I�s�R�A�禡TotalSold()�A�Ӥ��O�Ϊ���I�s
	cout << "All the hotdog stands sells " << HotDogStand::TotalSold() << " hotdogs." << endl;

	//���եΪ���I�sJustSold()�A�O�_�I�s�@���N�h��X�@��
	stand1.JustSold();
	stand2.JustSold();
	stand3.JustSold();

	cout << endl;
	cout << "Every stand sells more one hotdog. " << endl;
	cout << "The hotdog stand " << stand1.get_id() << " sells " << stand1.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand2.get_id() << " sells " << stand2.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand3.get_id() << " sells " << stand3.get_sold() << " hotdogs. " << endl;
	cout << "All the hotdog stands sells " << HotDogStand::TotalSold() << " hotdogs." << endl;

	system("pause");
	return 0;
}

int HotDogStand::total_sold = 0;					//��l��static�ܼƬ��s�A�n�b���O�w�q�϶����~��l��
HotDogStand::HotDogStand() :id(0), sold(0){}		//�w�]�غc�l��l�Ƭ��s
HotDogStand::HotDogStand(int id, int sold) {		
	this->id = id;									//��l��private�ݩʦ���
	this->sold = sold;
	total_sold = total_sold + sold;
}

void HotDogStand::JustSold() {
	sold++;											//���󥻨��h��X�@��
	total_sold++;									//�Ҧ������`�@�h��X�@��
}
int HotDogStand::TotalSold() {
	return total_sold;								//�^�ǩҦ�stand��X�������`��
}