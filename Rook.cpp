#include "Rook.h"
void Rook::valid_move(Piece*** const board, int** p_array, int p_moves)
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
	//up
	for (int i = y_position + 1; i < 8; i++)
	{
		if (board[x_position][i] == NULL)
		{
			v_moves++;
		}
		else if (this->get_Player() != board[x_position][i]->get_Player())
		{


			v_moves++;
			break;

		}
		else
		{
			break;
		}
	}
	//down
	for (int i = y_position - 1; i >= 0; i--)
	{
		if (board[x_position][i] == NULL)
		{
			v_moves++;
		}
		else if (this->get_Player() != board[x_position][i]->get_Player())
		{


			v_moves++;
			break;

		}
		else
		{
			break;
		}
	}
	//left
	for (int i = x_position + 1; i < 8; i++)
	{
		if (board[i][y_position] == NULL)
		{
			v_moves++;
		}
		else if (this->get_Player() != board[i][y_position]->get_Player())
		{


			v_moves++;
			break;

		}
		else
		{
			break;
		}
	}
	//right
	for (int i = x_position - 1; i >= 0; i--)
	{
		if (board[i][y_position] == NULL)
		{
			v_moves++;
		}
		else if (this->get_Player() != board[i][y_position]->get_Player())
		{


			v_moves++;
			break;

		}
		else
		{
			break;
		}
	}

	valid_move_array = new int* [v_moves];

	for (int i = 0; i < v_moves; i++)
	{
		valid_move_array[i] = new int[2];
	}

	for (int p = 0; p < v_moves;)
	{
		//up
		for (int i = y_position + 1; i < 8; i++)
		{
			if (board[x_position][i] == NULL)
			{
				valid_move_array[p][0] = i;
				valid_move_array[p++][1] = x_position;
			}
			else if (this->get_Player() != board[x_position][i]->get_Player())
			{


				valid_move_array[p][0] = i;
				valid_move_array[p++][1] = x_position;
				break;

			}
			else
			{
				break;
			}
		}
		//down
		for (int i = y_position - 1; i >= 0; i--)
		{
			if (board[x_position][i] == NULL)
			{
				valid_move_array[p][0] = i;
				valid_move_array[p++][1] = x_position;
			}
			else if (this->get_Player() != board[x_position][i]->get_Player())
			{


				valid_move_array[p][0] = i;
				valid_move_array[p++][1] = x_position;
				break;

			}
			else
			{
				break;
			}
		}
		//left
		for (int i = x_position + 1; i < 8; i++)
		{
			if (board[i][y_position] == NULL)
			{
				valid_move_array[p][0] = y_position;
				valid_move_array[p++][1] = i;
			}
			else if (this->get_Player() != board[i][y_position]->get_Player())
			{

				valid_move_array[p][0] = y_position;
				valid_move_array[p++][1] = i;
				break;

			}
			else
			{
				break;
			}
		}
		//right
		for (int i = x_position - 1; i >= 0; i--)
		{
			if (board[i][y_position] == NULL)
			{
				valid_move_array[p][0] = y_position;
				valid_move_array[p++][1] = i;
			}
			else if (this->get_Player() != board[i][y_position]->get_Player())
			{


				valid_move_array[p][0] = y_position;
				valid_move_array[p++][1] = i;
				break;

			}
			else
			{
				break;
			}
		}
	}
}