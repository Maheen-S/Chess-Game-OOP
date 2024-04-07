#include "Pawn.h"
void Pawn::valid_move(Piece*** const board, int** p_array, int p_moves)
{
	if (valid_move_array != NULL)
	{
		for (int i = 0; i < v_moves; i++)
		{
			delete[] valid_move_array[i];
		}

		delete[] valid_move_array;
	}
	v_moves = 0;
	//black
	if (Player == 0)
	{
		if (x_position == 1)
		{
			for (int i = (x_position + 1); i < (x_position + 3); i++)
			{
				if (board[i][y_position] == NULL)
				{
					v_moves++;
				}
			}
			if (x_position + 1 < 8 && y_position + 1 < 8)
			{
				if (board[x_position + 1][y_position + 1] != NULL)
				{
					if (this->get_Player() != board[x_position + 1][y_position + 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
			if (x_position + 1 < 8 && y_position - 1 >= 0)
			{
				if (board[x_position + 1][y_position - 1] != NULL)
				{
					if (this->get_Player() != board[x_position + 1][y_position - 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
		}
		else if (x_position != 1)
		{
			if (board[x_position + 1][y_position] == NULL)
			{
				v_moves++;
			}
			if (x_position + 1 < 8 && y_position + 1 < 8)
			{
				if (board[x_position + 1][y_position + 1] != NULL)
				{
					if (this->get_Player() != board[x_position + 1][y_position + 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
			if (x_position + 1 < 8 && y_position - 1 >= 0)
			{
				if (board[x_position + 1][y_position - 1] != NULL)
				{
					if (this->get_Player() != board[x_position + 1][y_position - 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
		}
	}

	//white
	else if (Player == 1)
	{
		if (x_position == 6)
		{
			for (int i = (x_position - 1); i > (x_position - 3); i--)
			{
				if (board[i][y_position] == NULL)
				{
					v_moves++;
				}
			}
			if (x_position - 1 >= 0 && y_position + 1 < 8)
			{
				if (board[x_position - 1][y_position + 1] != NULL)
				{
					if (this->get_Player() != board[x_position - 1][y_position + 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
			if (x_position - 1 >= 0 && y_position - 1 >= 0)
			{
				if (board[x_position - 1][y_position - 1] != NULL)
				{
					if (this->get_Player() != board[x_position - 1][y_position - 1]->get_Player())
					{
						v_moves++;
					}
				}
			}

		}
		else if (x_position != 6)
		{
			if (board[x_position - 1][y_position] == NULL)
			{
				v_moves++;
			}
			if (x_position - 1 >= 0 && y_position + 1 < 8)
			{
				if (board[x_position - 1][y_position + 1] != NULL)
				{
					if (this->get_Player() != board[x_position - 1][y_position + 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
			if (x_position - 1 >= 0 && y_position - 1 >= 0)
			{
				if (board[x_position - 1][y_position - 1] != NULL)
				{
					if (this->get_Player() != board[x_position - 1][y_position - 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
		}
	}



	valid_move_array = new int* [v_moves];

	for (int i = 0; i < v_moves; i++)
	{
		valid_move_array[i] = new int[2];
	}

	for (int p = 0; p < v_moves;)
	{
		//black
		if (Player == 0)
		{
			if (x_position == 1)
			{
				for (int i = (x_position + 1); i < (x_position + 3); i++)
				{
					if (board[i][y_position] == NULL)
					{
						valid_move_array[p][0] = y_position;
						valid_move_array[p++][1] = i;
					}
				}
				if (x_position + 1 < 8 && y_position + 1 < 8)
				{
					if (board[x_position + 1][y_position + 1] != NULL)
					{
						if (this->get_Player() != board[x_position + 1][y_position + 1]->get_Player())
						{
							valid_move_array[p][0] = y_position + 1;
							valid_move_array[p++][1] = x_position + 1;
						}
					}
				}
				if (x_position + 1 < 8 && y_position - 1 >= 0)
				{
					if (board[x_position + 1][y_position - 1] != NULL)
					{
						if (this->get_Player() != board[x_position + 1][y_position - 1]->get_Player())
						{
							valid_move_array[p][0] = y_position - 1;
							valid_move_array[p++][1] = x_position + 1;
						}
					}
				}
			}
			else if (x_position != 1)
			{
				if (board[x_position + 1][y_position] == NULL)
				{
					valid_move_array[p][0] = y_position;
					valid_move_array[p++][1] = x_position + 1;
				}
				if (x_position + 1 < 8 && y_position + 1 < 8)
				{
					if (board[x_position + 1][y_position + 1] != NULL)
					{
						if (this->get_Player() != board[x_position + 1][y_position + 1]->get_Player())
						{
							valid_move_array[p][0] = y_position + 1;
							valid_move_array[p++][1] = x_position + 1;
						}
					}
				}
				if (x_position + 1 < 8 && y_position - 1 >= 0)
				{
					if (board[x_position + 1][y_position - 1] != NULL)
					{
						if (this->get_Player() != board[x_position + 1][y_position - 1]->get_Player())
						{
							valid_move_array[p][0] = y_position - 1;
							valid_move_array[p++][1] = x_position + 1;
						}
					}
				}
			}
		}
		//white
		else if (Player == 1)
		{
			if (x_position == 6)
			{
				for (int i = (x_position - 1); i > (x_position - 3); i--)
				{
					if (board[i][y_position] == NULL)
					{
						valid_move_array[p][0] = y_position;
						valid_move_array[p++][1] = i;
					}
				}
				if (x_position - 1 >= 0 && y_position + 1 < 8)
				{
					if (board[x_position - 1][y_position + 1] != NULL)
					{
						if (this->get_Player() != board[x_position - 1][y_position + 1]->get_Player())
						{
							valid_move_array[p][0] = y_position + 1;
							valid_move_array[p++][1] = x_position - 1;
						}
					}
				}
				if (x_position - 1 >= 0 && y_position - 1 >= 0)
				{
					if (board[x_position - 1][y_position - 1] != NULL)
					{
						if (this->get_Player() != board[x_position - 1][y_position - 1]->get_Player())
						{
							valid_move_array[p][0] = y_position - 1;
							valid_move_array[p++][1] = x_position - 1;
						}
					}
				}

			}
			else if (x_position != 6)
			{
				if (board[x_position - 1][y_position] == NULL)
				{
					valid_move_array[p][0] = y_position;
					valid_move_array[p++][1] = x_position - 1;
				}
				if (x_position - 1 >= 0 && y_position + 1 < 8)
				{
					if (board[x_position - 1][y_position + 1] != NULL)
					{
						if (this->get_Player() != board[x_position - 1][y_position + 1]->get_Player())
						{
							valid_move_array[p][0] = y_position + 1;
							valid_move_array[p++][1] = x_position - 1;
						}
					}
				}
				if (x_position - 1 >= 0 && y_position - 1 >= 0)
				{
					if (board[x_position - 1][y_position - 1] != NULL)
					{
						if (this->get_Player() != board[x_position - 1][y_position - 1]->get_Player())
						{
							valid_move_array[p][0] = y_position - 1;
							valid_move_array[p++][1] = x_position - 1;
						}
					}
				}
			}
		}

	}
}