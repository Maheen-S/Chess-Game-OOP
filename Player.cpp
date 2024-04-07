#include "Player.h"

void Player::set_check(bool c)
{
	this->check = c;
}

bool Player::get_check()
{
	return check;
}
void Player::set_possible_moves(int p)
{
	if (possible_moves_array != NULL)
	{
		for (int i = 0; i < possible_moves; i++)
		{
			delete[] possible_moves_array[i];
		}

		delete[] possible_moves_array;
	}

	this->possible_moves = p;
}

int Player::get_possible_moves()
{
	return possible_moves;
}

void Player::set_possible_moves_array()
{

	possible_moves_array = new int* [possible_moves];
	for (int i = 0; i < possible_moves; i++)
	{
		possible_moves_array[i] = new int[2];
	}
}

int** Player::get_possible_moves_array()
{
	return possible_moves_array;
}


void Player::set_cnic(long long int c)
{
	this->cnic = c;
}
void Player::set_id(int i)
{
	this->id = i;
}

long long int Player::get_cnic()
{
	return cnic;
}
int Player::get_id()
{
	return id;
}

void Player::set_possible_moves_array(int** a)
{
	possible_moves_array = a;
}

void Player::Display()
{
	wcout << this->id << endl;
	wcout << this->name << endl;
	wcout << this->cnic << endl;
	
}