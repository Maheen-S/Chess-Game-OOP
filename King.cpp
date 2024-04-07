#include "King.h"

King::King(int x, int y, bool p)
{
	name = 'K';
	this->x_position = x;
	this->y_position = y;
	this->Player = p;
	if (this->Player == 1)
	{
		name += 32;
	}
}

void King::valid_move(Piece*** const board, int** p_array, int p_moves)
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

	bool is_valid = true;

	for (int i = x_position - 1; i <= x_position + 1; i++)
	{

		if (y_position + 1 < 8)
		{
			if ((i < 8) && (i >= 0))
			{
				for (int l = 0; l < p_moves; l++)
				{
					if (p_array[l][1] == i && p_array[l][0] == y_position + 1)
					{
						is_valid = false;
						break;
					}
				}

				if (is_valid == false)
				{
					continue;
				}

				if (board[i][y_position + 1] == NULL)
				{
					v_moves++;
				}
				else
				{
					if (this->get_Player() != board[i][y_position + 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
		}


	}

	is_valid = true;

	for (int i = x_position - 1; i <= x_position + 1; i++)
	{
		for (int l = 0; l < p_moves; l++)
		{
			if (p_array[l][1] == i && p_array[l][0] == y_position - 1)
			{
				is_valid = false;
				break;
			}
		}

		if (is_valid == false)
		{
			continue;
		}

		if (y_position - 1 >= 0)
		{
			if ((i < 8) && (i >= 0))
			{
				if (board[i][y_position - 1] == NULL)
				{
					v_moves++;
				}
				else
				{
					if (this->get_Player() != board[i][y_position - 1]->get_Player())
					{
						v_moves++;
					}
				}
			}
		}
	}


	is_valid = true;

	if (x_position - 1 >= 0)
	{
		for (int l = 0; l < p_moves; l++)
		{
			if (p_array[l][1] == x_position - 1 && p_array[l][0] == y_position)
			{
				is_valid = false;
				break;
			}
		}

		if (is_valid == true)
		{
			if (board[x_position - 1][y_position] == NULL)
			{
				v_moves++;
			}
			else
			{
				if (this->get_Player() != board[x_position - 1][y_position]->get_Player())
				{
					v_moves++;
				}
			}
		}

	}

	is_valid = true;

	if (x_position + 1 < 8)
	{
		for (int l = 0; l < p_moves; l++)
		{
			if (p_array[l][1] == x_position + 1 && p_array[l][0] == y_position)
			{
				is_valid = false;
				break;
			}
		}

		if (is_valid == true)
		{
			if (board[x_position + 1][y_position] == NULL)
			{
				v_moves++;
			}
			else
			{
				if (this->get_Player() != board[x_position + 1][y_position]->get_Player())
				{
					v_moves++;
				}
			}
		}
	}




	valid_move_array = new int* [v_moves];

	for (int i = 0; i < v_moves; i++)
	{
		valid_move_array[i] = new int[2];
	}

	//

	is_valid = true;

	for (int p = 0; p < v_moves;)
	{
		for (int i = x_position - 1; i <= x_position + 1; i++)
		{
			if (y_position + 1 < 8)
			{
				if ((i < 8) && (i >= 0))
				{
					for (int l = 0; l < p_moves; l++)
					{
						if (p_array[l][1] == i && p_array[l][0] == y_position + 1)
						{
							is_valid = false;
							break;
						}
					}

					if (is_valid == false)
					{
						continue;
					}

					if (board[i][y_position + 1] == NULL)
					{
						valid_move_array[p][0] = y_position + 1;
						valid_move_array[p++][1] = i;
					}
					else
					{
						if (this->get_Player() != board[i][y_position + 1]->get_Player())
						{
							valid_move_array[p][0] = y_position + 1;
							valid_move_array[p++][1] = i;
						}
					}
				}
			}

		}

		is_valid = true;

		for (int i = x_position - 1; i <= x_position + 1; i++)
		{

			for (int l = 0; l < p_moves; l++)
			{
				if (p_array[l][1] == i && p_array[l][0] == y_position - 1)
				{
					is_valid = false;
					break;
				}
			}

			if (is_valid == false)
			{
				continue;
			}

			if (y_position - 1 >= 0)
			{
				if ((i < 8) && (i >= 0))
				{
					if (board[i][y_position - 1] == NULL)
					{
						valid_move_array[p][0] = y_position - 1;
						valid_move_array[p++][1] = i;
					}
					else
					{
						if (this->get_Player() != board[i][y_position - 1]->get_Player())
						{
							valid_move_array[p][0] = y_position - 1;
							valid_move_array[p++][1] = i;
						}
					}
				}
			}
		}

		is_valid = true;

		if (x_position - 1 >= 0)
		{
			for (int l = 0; l < p_moves; l++)
			{
				if (p_array[l][1] == x_position - 1 && p_array[l][0] == y_position)
				{
					is_valid = false;
					break;
				}
			}

			if (is_valid == true)
			{
				if (board[x_position - 1][y_position] == NULL)
				{
					valid_move_array[p][0] = y_position;
					valid_move_array[p++][1] = x_position - 1;
				}
				else
				{
					if (this->get_Player() != board[x_position - 1][y_position]->get_Player())
					{
						valid_move_array[p][0] = y_position;
						valid_move_array[p++][1] = x_position - 1;
					}
				}
			}
		}

		if (x_position + 1 < 8)
		{
			for (int l = 0; l < p_moves; l++)
			{
				if (p_array[l][1] == x_position + 1 && p_array[l][0] == y_position)
				{
					is_valid = false;
					break;
				}
			}

			if (is_valid == true)
			{
				if (board[x_position + 1][y_position] == NULL)
				{
					valid_move_array[p][0] = y_position;
					valid_move_array[p++][1] = x_position + 1;
				}
				else
				{
					if (this->get_Player() != board[x_position + 1][y_position]->get_Player())
					{
						valid_move_array[p][0] = y_position;
						valid_move_array[p++][1] = x_position + 1;
					}
				}
			}
		}
	}
}