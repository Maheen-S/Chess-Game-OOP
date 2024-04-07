#include "Bishop.h"
void Bishop::valid_move(Piece*** const board, int** p_array, int p_moves)
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
	//first diagnol 
	int j = y_position + 1;
	for (int i = x_position + 1; i < board_row && j < board_col; i++)
	{
		if (i < board_row && j < board_col)
		{
			//valid_move_array[x_position+i][y_position+j]='o'
			if (board[i][j] == NULL)
			{
				v_moves++;
			}
			else if (this->get_Player() != board[i][j]->get_Player())
			{
				v_moves++;
				break;
			}
			else
			{
				break;
			}
		}
		j++;
	}

	j = y_position - 1;
	for (int i = x_position - 1; i >= 0 && j >= 0; i--)
	{
		if (i >= 0 && j >= 0)
		{
			if (board[i][j] == NULL)
			{
				v_moves++;
			}
			else if (this->get_Player() != board[i][j]->get_Player())
			{
				v_moves++;
				break;
			}
			else
			{
				break;
			}
		}
		j--;
	}

	// second diagnol
	j = y_position - 1;
	for (int i = x_position + 1; i < board_row && j >= 0; i++)
	{
		if (i < board_row && j >= 0)
		{
			if (board[i][j] == NULL)
			{
				v_moves++;
			}
			else if (this->get_Player() != board[i][j]->get_Player())
			{
				v_moves++;
				break;
			}
			else
			{
				break;
			}
		}
		j--;
	}

	j = y_position + 1;
	for (int i = x_position - 1; i >= 0 && j < board_col; i--)
	{
		if (i >= 0 && j < board_col)
		{
			if (board[i][j] == NULL)
			{
				v_moves++;
			}
			else if (this->get_Player() != board[i][j]->get_Player())
			{
				v_moves++;
				break;
			}
			else
			{
				break;
			}
		}
		j++;
	}



	valid_move_array = new int* [v_moves];

	for (int i = 0; i < v_moves; i++)
	{
		valid_move_array[i] = new int[2];
	}

	for (int p = 0; p < v_moves;)
	{
		//first diagnol 
		int j = y_position + 1;
		for (int i = x_position + 1; i < board_row && j < board_col; i++)
		{
			if (i < board_row && j < board_col)
			{
				if (board[i][j] == NULL)
				{
					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
				}
				else if (this->get_Player() != board[i][j]->get_Player())
				{


					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
					break;

				}
				else
				{
					break;
				}
			}
			j++;
		}

		j = y_position - 1;
		for (int i = x_position - 1; i >= 0 && j >= 0; i--)
		{
			if (i >= 0 && j >= 0)
			{
				if (board[i][j] == NULL)
				{
					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
				}
				else if (this->get_Player() != board[i][j]->get_Player())
				{


					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
					break;

				}
				else
				{
					break;
				}
			}
			j--;
		}

		// second diagnol
		j = y_position - 1;
		for (int i = x_position + 1; i < board_row && j >= 0; i++)
		{
			if (i < board_row && j >= 0)
			{
				if (board[i][j] == NULL)
				{
					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
				}
				else if (this->get_Player() != board[i][j]->get_Player())
				{


					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
					break;

				}
				else
				{
					break;
				}
			}
			j--;
		}

		j = y_position + 1;
		for (int i = x_position - 1; i >= 0 && j < board_col; i--)
		{
			if (i >= 0 && j < board_col)
			{
				if (board[i][j] == NULL)
				{
					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
				}
				else if (this->get_Player() != board[i][j]->get_Player())
				{


					valid_move_array[p][0] = j;
					valid_move_array[p++][1] = i;
					break;

				}
				else
				{
					break;
				}
			}
			j++;
		}
	}
}