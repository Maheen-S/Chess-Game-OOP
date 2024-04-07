#pragma once
#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

class User
{
protected: 
	char name[50];
	char password[50];
public: 
	char* get_name();
	char* get_password();
	void set_name(char* n);
	void set_password(char* p);
};

