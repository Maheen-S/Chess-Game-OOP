#include "Knight.h"
void Knight::valid_move(Piece*** const board, int** p_array, int p_moves)
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
	//bottom right move
	if (x_position - 2 >= 0 && y_position + 1 < 8)
	{
		if (board[x_position - 2][y_position + 1] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position - 2][y_position + 1]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//bottom left move
	if (x_position - 2 >= 0 && y_position - 1 >= 0)
	{
		if (board[x_position - 2][y_position - 1] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position - 2][y_position - 1]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//top right move
	if (x_position + 2 < 8 && y_position + 1 < 8)
	{
		if (board[x_position + 2][y_position + 1] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position + 2][y_position + 1]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//top left move
	if (x_position + 2 < 8 && y_position - 1 >= 0)
	{
		if (board[x_position + 2][y_position - 1] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position + 2][y_position - 1]->get_Player())
			{
				v_moves++;
			}
		}
	}

	//left top move
	if (x_position + 1 < 8 && y_position - 2 >= 0)
	{
		if (board[x_position + 1][y_position - 2] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position + 1][y_position - 2]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//left bottom move
	if (x_position - 1 >= 0 && y_position - 2 >= 0)
	{
		if (board[x_position - 1][y_position - 2] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position - 1][y_position - 2]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//right top move
	if (x_position + 1 < 8 && y_position + 2 < 8)
	{
		if (board[x_position + 1][y_position + 2] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position + 1][y_position + 2]->get_Player())
			{
				v_moves++;
			}
		}
	}
	//right bottom move
	if (x_position - 1 >= 0 && y_position + 2 < 8)
	{
		if (board[x_position - 1][y_position + 2] == NULL)
		{
			v_moves++;
		}
		else
		{
			if (this->get_Player() != board[x_position - 1][y_position + 2]->get_Player())
			{
				v_moves++;
			}
		}
	}



	//storing valid moves in an array
	valid_move_array = new int* [v_moves];

	for (int i = 0; i < v_moves; i++)
	{
		valid_move_array[i] = new int[2];
	}

	//

	for (int p = 0; p < v_moves;)
	{
		//bottom right move
		if (x_position - 2 >= 0 && y_position + 1 < 8)
		{
			if (board[x_position - 2][y_position + 1] == NULL)
			{
				valid_move_array[p][0] = y_position + 1;
				valid_move_array[p++][1] = x_position - 2;
			}
			else
			{
				if (this->get_Player() != board[x_position - 2][y_position + 1]->get_Player())
				{
					valid_move_array[p][0] = y_position + 1;
					valid_move_array[p++][1] = x_position - 2;
				}
			}
		}
		//bottom left move
		if (x_position - 2 >= 0 && y_position - 1 >= 0)
		{
			if (board[x_position - 2][y_position - 1] == NULL)
			{
				valid_move_array[p][0] = y_position - 1;
				valid_move_array[p++][1] = x_position - 2;
			}
			else
			{
				if (this->get_Player() != board[x_position - 2][y_position - 1]->get_Player())
				{
					valid_move_array[p][0] = y_position - 1;
					valid_move_array[p++][1] = x_position - 2;
				}
			}
		}
		//top right move
		if (x_position + 2 < 8 && y_position + 1 < 8)
		{
			if (board[x_position + 2][y_position + 1] == NULL)
			{
				valid_move_array[p][0] = y_position + 1;
				valid_move_array[p++][1] = x_position + 2;
			}
			else
			{
				if (this->get_Player() != board[x_position + 2][y_position + 1]->get_Player())
				{
					valid_move_array[p][0] = y_position + 1;
					valid_move_array[p++][1] = x_position + 2;
				}
			}
		}
		//top left move
		if (x_position + 2 < 8 && y_position - 1 >= 0)
		{
			if (board[x_position + 2][y_position - 1] == NULL)
			{
				valid_move_array[p][0] = y_position - 1;
				valid_move_array[p++][1] = x_position + 2;
			}
			else
			{
				if (this->get_Player() != board[x_position + 2][y_position - 1]->get_Player())
				{
					valid_move_array[p][0] = y_position - 1;
					valid_move_array[p++][1] = x_position + 2;
				}
			}
		}

		//left top move
		if (x_position + 1 < 8 && y_position - 2 >= 0)
		{
			if (board[x_position + 1][y_position - 2] == NULL)
			{
				valid_move_array[p][0] = y_position - 2;
				valid_move_array[p++][1] = x_position + 1;
			}
			else
			{
				if (this->get_Player() != board[x_position + 1][y_position - 2]->get_Player())
				{
					valid_move_array[p][0] = y_position - 2;
					valid_move_array[p++][1] = x_position + 1;
				}
			}
		}
		//left bottom move
		if (x_position - 1 >= 0 && y_position - 2 >= 0)
		{
			if (board[x_position - 1][y_position - 2] == NULL)
			{
				valid_move_array[p][0] = y_position - 2;
				valid_move_array[p++][1] = x_position - 1;
			}
			else
			{
				if (this->get_Player() != board[x_position - 1][y_position - 2]->get_Player())
				{
					valid_move_array[p][0] = y_position - 2;
					valid_move_array[p++][1] = x_position - 1;
				}
			}
		}
		//right top move
		if (x_position + 1 < 8 && y_position + 2 < 8)
		{
			if (board[x_position + 1][y_position + 2] == NULL)
			{
				valid_move_array[p][0] = y_position + 2;
				valid_move_array[p++][1] = x_position + 1;
			}
			else
			{
				if (this->get_Player() != board[x_position + 1][y_position + 2]->get_Player())
				{
					valid_move_array[p][0] = y_position + 2;
					valid_move_array[p++][1] = x_position + 1;
				}
			}
		}
		//right bottom move
		if (x_position - 1 >= 0 && y_position + 2 < 8)
		{
			if (board[x_position - 1][y_position + 2] == NULL)
			{
				valid_move_array[p][0] = y_position + 2;
				valid_move_array[p++][1] = x_position - 1;
			}
			else
			{
				if (this->get_Player() != board[x_position - 1][y_position + 2]->get_Player())
				{
					valid_move_array[p][0] = y_position + 2;
					valid_move_array[p++][1] = x_position - 1;
				}
			}
		}
	}




}