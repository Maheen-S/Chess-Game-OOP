#include "Temp_Piece.h"

void Temp_Piece::operator=(Piece* p)
{
	this->name = p->getName();
	this->x_p = p->get_x_position();
	this->y_p = p->get_y_position();
	this->player = p->get_Player();
}
char Temp_Piece::get_name()
{
	return name;
}
int Temp_Piece::get_x_p()
{
	return x_p;
}
int Temp_Piece::get_y_p()
{
	return y_p;
}
int Temp_Piece::get_player()
{
	return player;
}

