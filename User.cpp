#include "User.h"

char* User::get_name()
{
	return name;
}
char* User::get_password()
{
	return password;
}
void User::set_name(char* n)
{
	strcpy(this->name, n);
}
void User::set_password(char* p)
{
	strcpy(this->password, p);
}