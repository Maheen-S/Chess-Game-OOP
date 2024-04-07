#pragma once
#include "Pieces.h"

class Knight :
    public Piece
{
public:
    Knight(int x, int y, bool p)
    {
        name = 'N';
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

