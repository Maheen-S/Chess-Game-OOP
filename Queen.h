#pragma once
#include "Pieces.h"

class Queen:
	public Piece
{
public:
	Queen(int x, int y, bool p)
	{
		name = 'Q';
		this->x_position = x;
		this->y_position = y;
		this->Player = p;
		if (this->Player == 1)
		{
			name += 32;
		}
	}

	void valid_move(Piece*** const board, int** p_array, int p_moves);
	
};


