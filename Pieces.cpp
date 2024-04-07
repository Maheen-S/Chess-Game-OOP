#include "Pieces.h"

bool Piece::check_check(Piece*** const board, int** p_moves, int p, bool x)
{
	int i, j;
	bool flag = false;
	if (x == 0)
	{
		for (i = 0; i < board_row; i++)
		{
			for (j = 0; j < board_col; j++)
			{
				if (board[i][j] != NULL)
				{
					if (board[i][j]->getName() == 'k')
					{
						flag = true;
						break;
					}
				}

			}
			if (flag)
			{
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < board_row; i++)
		{
			for (j = 0; j < board_col; j++)
			{
				if (board[i][j] != NULL)
				{
					if (board[i][j]->getName() == 'K')
					{
						flag = true;
						break;
					}
				}
			}
			if (flag)
			{
				break;
			}
		}
	}



	for (int k = 0; k < p; k++)
	{

		if (p_moves[k][0] == j && p_moves[k][1] == i)
		{
			return 1;
		}
	}

	return 0;

}

bool Piece::get_Player()
{
	return Player;
}
int** Piece::get_valid_move_array()
{
	return valid_move_array;
}
int Piece::get_v_moves()
{
	return v_moves;
}

void Piece::set_x(int x_position)
{
	this->x_position = x_position;
}

void Piece::set_y(int y_position)
{
	this->y_position = y_position;
}

void buddy_display()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	wcout << "						    ================================================================================================================" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	wcout << "						    _____                ______      ______                 __   _____     _____   _    _  ______   _____  _____     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	wcout << "						    |  __ \\  | \\     / | |  ___  \\   |  ___  \\   \\\\      // |__| / ____|   |   ___ | |  | |   ____| / ____ / ____|     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						    | |__) | | |     | | | |   \\  \\  | |   \\  \\   \\\\    //     /  (___     | |     | |__| |  |__   | (___ | (___       " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	wcout << "						    |  __ (  | |     | | | |    )  ) | |    )  )   \\\\||//     /  \\___ \\    | |     |  __  |   __|  \\ ___ \\ \\___ \\     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	wcout << "						    | |__) | | \\_____/ | | |___/  /  | |___/  /      ||          ____) |   | |____ | |  | |  |____  ____)  ____) |     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						    |  ___/   \\_______/  |_______/   |_______/       ||           _____/   \\_____  |_|  |_|  ______| _____/ _____/     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	wcout << "						  =================================================================================================================" << endl;






	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Piece::draw_moves(Piece*** const pieces)
{
	system("CLS");
	buddy_display();
	wcout << endl << endl;

	wcout << "   \t\t\t\t\t\t\t\t\t\t";
	bool flag = false;
	
	for (char i = 'A'; i < 'I'; i++)
	{
		wcout << i << " ";
	}
	wcout << endl;
	wcout << "  ";
	for (int i = 0; i < 26; i++)
	{
		wcout << "_";
	}

	wcout << endl;

	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			flag = false;

			if (j == 0)
			{
				wcout <<"\t\t\t\t\t\t\t\t\t\t" << board_row - i << " |";
			}

			if (j % 2 == 1)
			{
				if (i % 2 == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					if (pieces[i][j] != NULL)
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
									break;
								}
							}

						}

						if (i == this->x_position)
						{
							if (j == this->y_position)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 242);
							}
						}

						wcout << " " << pieces[i][j]->name << " ";

					}
					else
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									wcout << " . ";
									flag = true;
								}
							}
						}

						if (!flag)
						{
							wcout << "   ";
						}

					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (pieces[i][j] != NULL)
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									break;
								}

							}

						}

						if (i == this->x_position)
						{
							if (j == this->y_position)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							}
						}

						wcout << " " << pieces[i][j]->name << " ";
					}
					else
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									wcout << " . ";
									flag = true;
								}
							}
						}

						if (!flag)
						{
							wcout << "   ";
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
			else
			{

				if (i % 2 == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (pieces[i][j] != NULL)
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									break;
								}
							}

						}

						if (i == this->x_position)
						{
							if (j == this->y_position)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							}
						}

						wcout << " " << pieces[i][j]->name << " ";
					}
					else
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									wcout << " . ";
									flag = true;
								}
							}
						}

						if (!flag)
						{
							wcout << "   ";
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					if (pieces[i][j] != NULL)
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
									break;
								}
							}

						}

						if (i == this->x_position)
						{
							if (j == this->y_position)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 242);
							}
						}

						wcout << " " << pieces[i][j]->name << " ";
					}
					else
					{
						for (int p = 0; p < v_moves; p++)
						{
							if ((i == valid_move_array[p][1]))
							{
								if ((j == valid_move_array[p][0]))
								{
									wcout << " . ";
									flag = true;
								}
							}
						}

						if (!flag)
						{
							wcout << "   ";
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
			if (j == 7)
			{
				wcout << "|";
			}

		}

		wcout << endl;
	}

	wcout << "  \t\t\t\t\t\t\t\t\t\t";


	for (int i = 0; i < 26; i++)
	{
		wcout << L"‾";
	}

	wcout << endl << endl;

	wcout << "Captured Pieces:\n";
	wcout << "Black: ";

	for (int i = 0; i < 16; i++)
	{
		if (captured_blacks_array[i] == '0')
		{
			break;
		}
		else
		{
			wcout << captured_blacks_array[i];
			if (i < 15)
			{
				wcout << ", ";
			}
		}
	}

	wcout << endl;
	wcout << "White: ";

	for (int i = 0; i < 16; i++)
	{
		if (captured_whites_array[i] == '0')
		{
			break;
		}
		else
		{
			wcout << captured_whites_array[i];
			if (i < 15)
			{
				if (captured_whites_array[i + 1] != '0')
				{
					wcout << ", ";
				}

			}
		}
	}



}

char Piece::getName() const
{
	return name;
}





int Piece::get_x_position()
{
	return x_position;
}
int Piece::get_y_position()
{
	return y_position;
}

void Piece::set_player(bool p)
{
	this->Player = p;
}

void Piece::set_name(char n)
{
	this->name = n;
}

void Piece::set_v_moves(int v)
{
	this->v_moves = v;
}


void Piece::set_valid_move_player(int** v)
{
	this->valid_move_array = v;
}