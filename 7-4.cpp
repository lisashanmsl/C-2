#include<iostream>
#include<cstdlib>
using namespace std;

class HotDogStand {
public:
	HotDogStand();							//預設建構子
	HotDogStand(int id, int sold);			//初始化private屬性成員的建構子

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
	static int total_sold;					//靜態成員屬於類別，而不屬於個別的物件，常使用類別名稱加上::來使用
};

int main(void) {
	HotDogStand stand1(1, 20), stand2(2, 15), stand3(3, 10);		//用建構子創建三個HotDogStand物件，並初始化完成set

	cout << "The hotdog stand " << stand1.get_id() << " sells " << stand1.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand2.get_id() << " sells " << stand2.get_sold() << " hotdogs. " << endl;
	cout << "The hotdog stand " << stand3.get_id() << " sells " << stand3.get_sold() << " hotdogs. " << endl;

	//用類別呼叫靜態函式TotalSold()，而不是用物件呼叫
	cout << "All the hotdog stands sells " << HotDogStand::TotalSold() << " hotdogs." << endl;

	//測試用物件呼叫JustSold()，是否呼叫一次就多賣出一個
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

int HotDogStand::total_sold = 0;					//初始化static變數為零，要在類別定義區塊之外初始化
HotDogStand::HotDogStand() :id(0), sold(0){}		//預設建構子初始化為零
HotDogStand::HotDogStand(int id, int sold) {		
	this->id = id;									//初始化private屬性成員
	this->sold = sold;
	total_sold = total_sold + sold;
}

void HotDogStand::JustSold() {
	sold++;											//物件本身多賣出一個
	total_sold++;									//所有物件總共多賣出一個
}
int HotDogStand::TotalSold() {
	return total_sold;								//回傳所有stand賣出的熱狗總數
}