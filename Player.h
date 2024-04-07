#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "User.h"
using namespace std;
class Player :
		public User
{
private:
	int possible_moves;
	int** possible_moves_array;
	bool check;
	long long int cnic;
	int id;
public:
	Player()
	{
		check = false;
		possible_moves = 0;
		possible_moves_array = NULL;
		cnic = 0;
		id = 0;
	}

	void Display();
	void set_check(bool c);
	bool get_check();
	void set_possible_moves(int p);
	int get_possible_moves();
	void set_possible_moves_array();
	void set_possible_moves_array(int **a);
	int** get_possible_moves_array();

	void set_cnic(long long int c);
	void set_id(int i);
	long long int get_cnic();
	int get_id();

};