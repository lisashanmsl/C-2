//判斷登入者身分
#include<iostream>
#include<string>
#include"Administrator.h"
#include"User.h"
using namespace std;

int main(void)
{
	Administrator adm;
	User user;

	string adm_username = "abbott";
	string adm_password = "monday";
	string user_username = "costello";
	string user_password = "tuesday";
	
	if (adm.Login(adm_username, adm_password)) {
		cout << "Administrator login success! " << endl;
	}
	else cout << "Administrator login fail. " << endl;

	if (user.Login(user_username, user_password)) {
		cout << "User login success! " << endl;
	}
	else cout << "User login fail. " << endl;

	system("pause");
	return 0;
}