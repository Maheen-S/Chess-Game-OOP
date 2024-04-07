#pragma once
#include "Pieces.h"

class King :
	public Piece
{
public:
	King(int x, int y, bool p);
	void valid_move(Piece*** const board, int** p_array, int p_moves);

};

