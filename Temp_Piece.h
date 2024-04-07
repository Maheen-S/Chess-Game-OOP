#pragma once
#include "Pieces.h"
class Temp_Piece
{
private:
	char name;
	int x_p;
	int y_p;
	int player;
public:
	void operator=(Piece* p);
	char get_name();
	int get_x_p();
	int get_y_p();
	int get_player();
};

