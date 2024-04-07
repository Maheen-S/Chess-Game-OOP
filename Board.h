#pragma once
#include "Player.h"
#include "Pieces.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Player.h"


class Board
{
private:
	Piece*** pieces;
	Player* p_zero;
	Player* p_one;

public:
	Piece*** get_pieces();

	Board(Player* p0, Player* p1);

	void display();
	void store_moves(int y, int x);
	void all_possible_moves();
	bool check_check_mate(bool player);
	bool check_draw(bool p);
	int move(int x1, int y1, int x2, int y2, bool p);
	bool get_check(bool x);
	int get_v_moves(int x, int y);

	~Board()
	{
		for (int i = 0; i < board_row; i++)
		{
			for (int j = 0; j < board_col; j++)
			{
				if (pieces[i][j] != NULL)
				{
					delete[] pieces[i][j];
				}
			}
		}
	}

};

