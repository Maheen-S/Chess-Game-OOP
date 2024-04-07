#include "Board.h"
int Piece::captured_blacks = 0;
int Piece::captured_whites = 0;

char* Piece::captured_whites_array = new char[16]{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
char* Piece::captured_blacks_array = new char[16]{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };


Board::Board(Player* p0, Player* p1)
{
	p_zero = p0;
	p_one = p1;
	_setmode(_fileno(stdout), 0x00020000);
	pieces = new Piece * *[board_row];
	for (int i = 0; i < board_row; i++)
	{
		pieces[i] = new Piece * [board_col];
	}

	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			if ((i == 0) && (j == 0) || (i == 0) && (j == 7))
			{
				pieces[i][j] = new Rook(i, j, 0);
			}
			else if ((i == 7) && (j == 0) || (i == 7) && (j == 7))
			{
				pieces[i][j] = new Rook(i, j, 1);
			}
			else if ((i == 0) && (j == 1) || (i == 0) && (j == 6))
			{
				pieces[i][j] = new Knight(i, j, 0);
			}
			else if ((i == 7) && (j == 1) || (i == 7) && (j == 6))
			{
				pieces[i][j] = new Knight(i, j, 1);
			}
			else if ((i == 0) && (j == 2) || (i == 0) && (j == 5))
			{
				pieces[i][j] = new Bishop(i, j, 0);
			}
			else if ((i == 7) && (j == 2) || (i == 7) && (j == 5))
			{
				pieces[i][j] = new Bishop(i, j, 1);
			}
			else if ((i == 0) && (j == 3))
			{
				pieces[i][j] = new Queen(i, j, 0);
			}
			else if ((i == 7) && (j == 3))
			{
				pieces[i][j] = new Queen(i, j, 1);
			}
			else if ((i == 0) && (j == 4))
			{
				pieces[i][j] = new King(i, j, 0);
			}
			else if ((i == 7) && (j == 4))
			{
				pieces[i][j] = new King(i, j, 1);
			}
			else if ((i == 1))
			{
				pieces[i][j] = new Pawn(i, j, 0);
			}
			else if ((i == 6))
			{
				pieces[i][j] = new Pawn(i, j, 1);
			}
			else
			{
				pieces[i][j] = NULL;
			}
		}

	}

}

Piece*** Board:: get_pieces()
{
	return pieces;
}

//void buddy_display()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//	cout << "						    ================================================================================================================" << endl;
//	SetConsoleTextAtt-ribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//	cout << "						    _____                ______      ______                 __   _____     _____   _    _  ______   _____  _____     " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
//	cout << "						    |  __ \\  | \\     / | |  ___  \\   |  ___  \\   \\\\      // |__| / ____|   |   ___ | |  | |   ____| / ____ / ____|     " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//	cout << "						    | |__) | | |     | | | |   \\  \\  | |   \\  \\   \\\\    //     /  (___     | |     | |__| |  |__   | (___ | (___       " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "						    |  __ (  | |     | | | |    )  ) | |    )  )   \\\\||//     /  \\___ \\    | |     |  __  |   __|  \\ ___ \\ \\___ \\     " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
//	cout << "						    | |__) | | \\_____/ | | |___/  /  | |___/  /      ||          ____) |   | |____ | |  | |  |____  ____)  ____) |     " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
//	cout << "						    |  ___/   \\_______/  |_______/   |_______/       ||           _____/   \\_____  |_|  |_|  ______| _____/ _____/     " << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
//	cout << "						  =================================================================================================================" << endl;
//
//
//
//
//
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//}

void Board::display()
{
	system("CLS");

	buddy_display();
	wcout << endl << endl;
	
	wcout << "   \t\t\t\t\t\t\t\t\t\t    ";
	for (char i = 'A'; i < 'I'; i++)
	{
		wcout << i << "  ";
	}
	wcout << endl;
	wcout << "  \t\t\t\t\t\t\t\t\t\t  ";
	
	for (int i = 0; i < 26; i++)
	{
		wcout << L"_";
	}
	wcout << endl;
	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			if (j == 0)
			{
				wcout << "\t\t\t\t\t\t\t\t\t\t" << board_row - i << " |";
			}

			if (j % 2 == 1)
			{
				if (i % 2 == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					if (pieces[i][j] != NULL)
					{

						wcout << " " << pieces[i][j]->getName() << " ";
					}
					else
					{
						wcout << "   ";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (pieces[i][j] != NULL)
					{
						wcout << " " << pieces[i][j]->getName() << " ";
					}
					else
					{
						wcout << "   ";
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
						wcout << " " << pieces[i][j]->getName() << " ";
					}
					else
					{
						wcout << "   ";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					if (pieces[i][j] != NULL)
					{
						wcout << " " << pieces[i][j]->getName() << " ";
					}
					else
					{
						wcout << "   ";
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
	wcout << "  \t\t\t\t\t\t\t\t\t\t  ";

	for (int i = 0; i < 26; i++)
	{
		wcout << L"‾";
	}

}

void Board::store_moves(int y, int x)
{
	if (pieces[y][x]->getName() == 'K')
	{
		pieces[y][x]->valid_move(pieces, p_one->get_possible_moves_array(), p_one->get_possible_moves());
	}
	else if (pieces[y][x]->getName() == 'k')
	{
		pieces[y][x]->valid_move(pieces, p_zero->get_possible_moves_array(), p_zero->get_possible_moves());
	}
	else
	{
		pieces[y][x]->valid_move(pieces);
	}

	pieces[y][x]->draw_moves(pieces);
}

void Board::all_possible_moves()
{
	int p_zero_moves = 0, p_one_moves = 0;
	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			if (pieces[i][j] != NULL)
			{
				if (pieces[i][j]->get_Player() == 0)
				{
					pieces[i][j]->valid_move(pieces);
					p_zero_moves += pieces[i][j]->get_v_moves();
				}
				else
				{
					pieces[i][j]->valid_move(pieces);
					p_one_moves += pieces[i][j]->get_v_moves();
				}
			}
		}
	}

	p_zero->set_possible_moves(p_zero_moves);
	p_one->set_possible_moves(p_one_moves);

	p_zero->set_possible_moves_array();
	p_one->set_possible_moves_array();

	int x = 0;
	int y = 0;
	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			if (pieces[i][j] != NULL)
			{
				if (pieces[i][j]->get_Player() == 0)
				{
					int v_m = pieces[i][j]->get_v_moves();
					for (int p = 0; p < v_m; p++)
					{
						p_zero->get_possible_moves_array()[x][0] = pieces[i][j]->get_valid_move_array()[p][0];
						p_zero->get_possible_moves_array()[x++][1] = pieces[i][j]->get_valid_move_array()[p][1];
					}

				}
				else
				{
					int v_m = pieces[i][j]->get_v_moves();
					for (int p = 0; p < v_m; p++)
					{
						p_one->get_possible_moves_array()[y][0] = pieces[i][j]->get_valid_move_array()[p][0];
						p_one->get_possible_moves_array()[y++][1] = pieces[i][j]->get_valid_move_array()[p][1];
					}
				}
			}
		}
	}
}

bool Board::check_check_mate(bool player)
{
	bool check_mate = true;

	if (player == 0)
	{
		for (int i = 0; i < board_row; i++)
		{
			for (int j = 0; j < board_col; j++)
			{
				if (pieces[i][j] != NULL)
				{
					if (pieces[i][j]->get_Player() == 0)
					{
						pieces[i][j]->valid_move(pieces);
						int v_m = pieces[i][j]->get_v_moves();
						for (int p = 0; p < v_m; p++)
						{
							pieces[i][j]->valid_move(pieces);
							int y2 = pieces[i][j]->get_valid_move_array()[p][0];
							int x2 = pieces[i][j]->get_valid_move_array()[p][1];

							char name_zero = pieces[i][j]->getName();

							char name_one = '0';

							if (pieces[x2][y2] != NULL)
							{
								name_one = pieces[x2][y2]->getName();
							}


							pieces[x2][y2] = pieces[i][j];
							pieces[i][j] = NULL;

							pieces[x2][y2]->set_x(x2);
							pieces[x2][y2]->set_y(y2);

							all_possible_moves();

							p_zero->set_check(pieces[x2][y2]->check_check(pieces, p_one->get_possible_moves_array(), p_one->get_possible_moves(), 1));

							if (p_zero->get_check() == 0)
							{
								check_mate = false;

							}

							switch (name_zero)
							{
							case 'K':
								pieces[i][j] = new King(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'Q':
								pieces[i][j] = new Queen(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'B':
								pieces[i][j] = new Bishop(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'N':
								pieces[i][j] = new Knight(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'P':
								pieces[i][j] = new Pawn(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'R':
								pieces[i][j] = new Rook(i, j, 0);
								pieces[i][j]->valid_move(pieces);
								break;

							}


							if (name_one != '0')
							{
								switch (name_one)
								{
								case 'k':
									pieces[x2][y2] = new King(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'q':
									pieces[x2][y2] = new Queen(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'b':
									pieces[x2][y2] = new Bishop(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'n':
									pieces[x2][y2] = new Knight(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'p':
									pieces[x2][y2] = new Pawn(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'r':
									pieces[x2][y2] = new Rook(x2, y2, 1);
									pieces[x2][y2]->valid_move(pieces);
									break;

								}
							}
							else
							{
								pieces[x2][y2] = NULL;
							}

						}



					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < board_row; i++)
		{
			for (int j = 0; j < board_col; j++)
			{
				if (pieces[i][j] != NULL)
				{
					if (pieces[i][j]->get_Player() == 1)
					{
						pieces[i][j]->valid_move(pieces);
						int v_m = pieces[i][j]->get_v_moves();
						for (int p = 0; p < v_m; p++)
						{
							pieces[i][j]->valid_move(pieces);
							int y2 = pieces[i][j]->get_valid_move_array()[p][0];
							int x2 = pieces[i][j]->get_valid_move_array()[p][1];

							char name_one = pieces[i][j]->getName();
							char name_zero = '0';

							if (pieces[x2][y2] != NULL)
							{
								name_zero = pieces[x2][y2]->getName();
							}


							pieces[x2][y2] = pieces[i][j];
							pieces[i][j] = NULL;

							pieces[x2][y2]->set_x(x2);
							pieces[x2][y2]->set_y(y2);

							all_possible_moves();

							p_one->set_check(pieces[x2][y2]->check_check(pieces, p_zero->get_possible_moves_array(), p_zero->get_possible_moves(), 0));

							if (p_one->get_check() == 0)
							{
								check_mate = false;

							}

							switch (name_one)
							{
							case 'k':
								pieces[i][j] = new King(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'q':
								pieces[i][j] = new Queen(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'b':
								pieces[i][j] = new Bishop(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'n':
								pieces[i][j] = new Knight(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'p':
								pieces[i][j] = new Pawn(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;
							case 'r':
								pieces[i][j] = new Rook(i, j, 1);
								pieces[i][j]->valid_move(pieces);
								break;

							}


							if (name_zero != '0')
							{
								switch (name_zero)
								{
								case 'K':
									pieces[x2][y2] = new King(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'Q':
									pieces[x2][y2] = new Queen(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'B':
									pieces[x2][y2] = new Bishop(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'N':
									pieces[x2][y2] = new Knight(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'P':
									pieces[x2][y2] = new Pawn(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;
								case 'R':
									pieces[x2][y2] = new Rook(x2, y2, 0);
									pieces[x2][y2]->valid_move(pieces);
									break;

								}
							}
							else
							{
								pieces[x2][y2] = NULL;
							}
						}
					}
				}
			}
		}

	}

	return check_mate;

}

bool Board::check_draw(bool p)
{
	bool draw = false;
	bool flag = false;
	int i;
	int j;

	for (i = 0; i < board_row; i++)
	{
		for (j = 0; j < board_col; j++)
		{
			if (pieces[i][j] != NULL)
			{
				if (pieces[i][j]->getName() == 'K')
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

	if (pieces[i][j]->get_v_moves() == 0 && p_zero->get_check())
	{
		draw = true;
	}

	flag = false;

	int q, w;

	for (q = 0; q < board_row; q++)
	{

		for (w = 0; w < board_col; w++)
		{
			if (pieces[q][w] != NULL)
			{
				if (pieces[q][w]->getName() == 'k')
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


	if (pieces[q][w]->get_v_moves() == 0 && p_one->get_check() == 1)
	{
		draw = true;
	}

	if (draw == false)
	{
		if (Piece::captured_blacks_array[14] != '0' && Piece::captured_whites_array[14] != '0')
		{
			draw = true;
		}
	}

	if (draw == false)
	{
		int bishop_count = 0;
		if (Piece::captured_blacks_array[14] != '0')
		{
			for (i = 0; i < 16; i++)
			{
				if (Piece::captured_whites_array[i] == 'b')
				{
					bishop_count++;
				}
			}
			if (bishop_count == 1)
			{
				draw = true;
			}
		}
		else if (Piece::captured_whites_array[14] != '0')
		{
			for (i = 0; i < 16; i++)
			{
				if (Piece::captured_blacks_array[i] == 'B')
				{
					bishop_count++;
				}
			}
			if (bishop_count == 1)
			{
				draw = true;
			}
		}
	}


	if (draw == false)
	{
		int knight_count = 0;
		if (Piece::captured_blacks_array[14] != '0')
		{
			for (i = 0; i < 16; i++)
			{
				if (Piece::captured_whites_array[i] == 'n')
				{
					knight_count++;
				}
			}
			if (knight_count == 1)
			{
				draw = true;
			}
		}
		else if (Piece::captured_whites_array[14] != '0')
		{
			for (i = 0; i < 16; i++)
			{
				if (Piece::captured_blacks_array[i] == 'N')
				{
					knight_count++;
				}
			}
			if (knight_count == 1)
			{
				draw = true;
			}
		}
	}

	return draw;
}

int Board::move(int x1, int y1, int x2, int y2, bool p)
{
	int flag = 2;
	int v_m = pieces[x1][y1]->get_v_moves();
	int valid_move = 0;

	for (int i = 0; i < v_m; i++)
	{
		if ((pieces[x1][y1]->get_valid_move_array()[i][0] == y2) && (pieces[x1][y1]->get_valid_move_array()[i][1] == x2))
		{
			valid_move = 2;
			break;
		}
	}

	if (valid_move != 2)
	{
		flag = 0;
	}

	if (valid_move)
	{

		if (p == 0)
		{
			if (p_zero->get_check())
			{
				char name_zero = pieces[x1][y1]->getName();

				char name_one = '0';

				if (pieces[x2][y2] != NULL)
				{
					name_one = pieces[x2][y2]->getName();
				}


				pieces[x2][y2] = pieces[x1][y1];
				pieces[x1][y1] = NULL;

				pieces[x2][y2]->set_x(x2);
				pieces[x2][y2]->set_y(y2);

				all_possible_moves();

				p_zero->set_check(pieces[x2][y2]->check_check(pieces, p_one->get_possible_moves_array(), p_one->get_possible_moves(), 1));

				if (p_zero->get_check() == 0)
				{
					flag = 2;

				}
				else
				{
					flag = 1;
				}

				switch (name_zero)
				{
				case 'K':
					pieces[x1][y1] = new King(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'Q':
					pieces[x1][y1] = new Queen(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'B':
					pieces[x1][y1] = new Bishop(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'N':
					pieces[x1][y1] = new Knight(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'P':
					pieces[x1][y1] = new Pawn(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'R':
					pieces[x1][y1] = new Rook(x1, y1, 0);
					pieces[x1][y1]->valid_move(pieces);
					break;

				}


				if (name_one != '0')
				{
					switch (name_one)
					{
					case 'k':
						pieces[x2][y2] = new King(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'q':
						pieces[x2][y2] = new Queen(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'b':
						pieces[x2][y2] = new Bishop(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'n':
						pieces[x2][y2] = new Knight(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'p':
						pieces[x2][y2] = new Pawn(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'r':
						pieces[x2][y2] = new Rook(x2, y2, 1);
						pieces[x2][y2]->valid_move(pieces);
						break;

					}
				}
				else
				{
					pieces[x2][y2] = NULL;
				}

			}



		}
		else
		{
			if (p_one->get_check())
			{
				char name_one = pieces[x1][y1]->getName();
				char name_zero = '0';

				if (pieces[x2][y2] != NULL)
				{
					name_zero = pieces[x2][y2]->getName();
				}


				pieces[x2][y2] = pieces[x1][y1];
				pieces[x1][y1] = NULL;

				pieces[x2][y2]->set_x(x2);
				pieces[x2][y2]->set_y(y2);

				all_possible_moves();

				p_one->set_check(pieces[x2][y2]->check_check(pieces, p_zero->get_possible_moves_array(), p_zero->get_possible_moves(), 0));

				if (p_one->get_check() == 0)
				{
					flag = 2;

				}
				else
				{
					flag = 1;
				}

				switch (name_one)
				{
				case 'k':
					pieces[x1][y1] = new King(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'q':
					pieces[x1][y1] = new Queen(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'b':
					pieces[x1][y1] = new Bishop(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'n':
					pieces[x1][y1] = new Knight(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'p':
					pieces[x1][y1] = new Pawn(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;
				case 'r':
					pieces[x1][y1] = new Rook(x1, y1, 1);
					pieces[x1][y1]->valid_move(pieces);
					break;

				}


				if (name_zero != '0')
				{
					switch (name_zero)
					{
					case 'K':
						pieces[x2][y2] = new King(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'Q':
						pieces[x2][y2] = new Queen(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'B':
						pieces[x2][y2] = new Bishop(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'N':
						pieces[x2][y2] = new Knight(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'P':
						pieces[x2][y2] = new Pawn(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;
					case 'R':
						pieces[x2][y2] = new Rook(x2, y2, 0);
						pieces[x2][y2]->valid_move(pieces);
						break;

					}
				}
				else
				{
					pieces[x2][y2] = NULL;
				}

			}
		}


	}



	if (flag == 2)
	{
		valid_move = 2;
	}
	else if (flag == 1)
	{
		valid_move = 1;
		display();
		wcout << "\nYou cannot make this move.\n";

	}
	else
	{
		valid_move = 0;
	}

	if (valid_move == 2)
	{
		bool player = pieces[x1][y1]->get_Player();

		if (pieces[x1][y1]->getName() == 'p' || pieces[x1][y1]->getName() == 'P')
		{
			int promotion_opt;
			if (((pieces[x1][y1]->get_Player() == 0) && x2 == 7) || ((pieces[x1][y1]->get_Player() == 1) && x2 == 0))
			{
				wcout << " \n Pawn has reached the Promotion state!"
					<< "\n What do you want to promote it to: "
					<< "\n 1: Queen \n 2: Rook \n 3: Bishop \n 4: Knight \n";
				cin >> promotion_opt;


				delete pieces[x1][y1];

				switch (promotion_opt)
				{
				case 1:
					pieces[x1][y1] = new Queen(x1, y1, player);
					break;
				case 2:
					pieces[x1][y1] = new Rook(x1, y1, player);
					break;
				case 3:
					pieces[x1][y1] = new Bishop(x1, y1, player);
					break;
				case 4:
					pieces[x1][y1] = new Knight(x1, y1, player);
					break;

				}
			}




		}

		if (pieces[x2][y2] != NULL)
		{
			if (pieces[x2][y2]->get_Player() == 0)
			{
				Piece::captured_blacks_array[Piece::captured_blacks++] = pieces[x2][y2]->getName();
			}
			else
			{
				Piece::captured_whites_array[Piece::captured_whites++] = pieces[x2][y2]->getName();
			}

			delete pieces[x2][y2];
			pieces[x2][y2] = NULL;

		}



		pieces[x2][y2] = pieces[x1][y1];
		pieces[x1][y1] = NULL;

		pieces[x2][y2]->set_x(x2);
		pieces[x2][y2]->set_y(y2);

		all_possible_moves();

		if (pieces[x2][y2]->getName() >= 65 && pieces[x2][y2]->getName() <= 90)
		{
			p_one->set_check(pieces[x2][y2]->check_check(pieces, p_zero->get_possible_moves_array(), p_zero->get_possible_moves(), 0));

		}
		else
		{
			p_zero->set_check(pieces[x2][y2]->check_check(pieces, p_one->get_possible_moves_array(), p_one->get_possible_moves(), 1));
		}

	}

	display();

	if (valid_move != 0 && valid_move != 1)
	{
		if (p_zero->get_check())
		{
			if (check_check_mate(0) == true)
			{
				valid_move = 4;
			}
		}
		else if (p_one->get_check())
		{
			if (check_check_mate(1) == true)
			{
				valid_move = 4;
			}
		}

		if (check_draw(p) == true)
		{
			valid_move = 5;
		}
	}

	return valid_move;

}

bool Board::get_check(bool x)
{
	if (x == 0)
	{
		return p_zero->get_check();
	}
	else
	{
		return p_one->get_check();
	}
}

int Board::get_v_moves(int x, int y)
{
	return pieces[x][y]->get_v_moves();
}

