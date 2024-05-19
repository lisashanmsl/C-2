#include"User.h"
#include"Security.h"

bool User::Login(std::string username, std::string password)
{
	int valid = Security::validate(username, password);
	return (valid == 1 || valid == 2);
}