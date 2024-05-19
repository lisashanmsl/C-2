#include"Administrator.h"
#include"Security.h"

bool Administrator::Login(std::string username, std::string password)
{
	return (Security::validate(username, password) == 1);
}