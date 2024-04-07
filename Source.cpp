#include "main_header.h"

int main()
{
	int user, op;
	Player p_zero;
	Player p_one;
	int menu_op;

	display_buddy();

	do
	{
		user = display_user_menu();
		if (user != 1 && user != 2)
		{
			system("CLS");
			display_buddy();
			//Reporting problem
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\tERROR: WRONG INPUT! TRY AGAIN." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			wcout << ".\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	} while (user != 1 && user != 2);

	if (user == 1)
	{
		do
		{
			system("CLS");
			display_buddy();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\t1._      P L A Y E R   O N E   _";




			op = login_register();

			if (op != 1 && op != 2)
			{
				system("CLS");
				display_buddy();
				//Reporting problem
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\tERROR: WRONG INPUT! TRY AGAIN." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				wcout << ".\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

		} while (op != 1 && op != 2);

		if (op == 1)
		{
			login(p_zero);
		}
		else if (op == 2)
		{
			registration(p_zero);
		}

		do {


			system("CLS");
			display_buddy();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\t1._      P L A Y E R   T W O   _";

			op = login_register();

			if (op != 1 && op != 2)
			{
				system("CLS");
				display_buddy();
				//Reporting problem
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\tERROR: WRONG INPUT! TRY AGAIN." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				wcout << ".\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

			if (op == 1)
			{
				login(p_one);
			}
			else if (op == 2)
			{
				registration(p_one);
			}
		} while (op != 1 && op != 2);

		Board chess_board(&p_zero, &p_one);
		string file_name = to_string(p_zero.get_id());

		file_name.append(to_string(p_one.get_id()));
		file_name.append(".dat");

		do
		{
			menu_op = display_main_menu();
			

			switch (menu_op)

			{
			case 1:
				break;
			case 2:
				load_state(chess_board.get_pieces(), file_name);
				break;

			case 3:
				stats(p_zero, p_one);
				break;
			case 4:
				rules();
				break;
			case 5:
				how_to_play();
				break;
			case 6:
				About_us();
				break;
			case 7:
				break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
				wcout << "													Invalid Option" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			}
		} while ((menu_op > 2 || menu_op < 1) && menu_op != 7);

		if (menu_op == 1 || menu_op == 2)
		{
			chess_board.display();
			bool player = 1;
			bool change = 0;
			int flag;

			do
			{
				char col;
				bool valid = 0;
				int c1 = 0, r1 = 0, c2 = 0, r2 = 0;
				wcout << endl;
				if (player == 1)
				{

					wcout << "White's turn" << endl;
					if (chess_board.get_check(player))
					{
						wcout << "\nYou're in Check.\n\n";
					}
				}
				else
				{
					wcout << "Black's turn" << endl;
					if (chess_board.get_check(player))
					{
						wcout << "\nYou're in Check.\n\n";
					}
				}

				do
				{


					do
					{
						//choosing the piece to move
						do
						{
							wcout << "Enter the coordinates of the piece you want to move: " << endl;
							//taking column
							wcout << "Enter the column:" << endl;
							do
							{
								col = get_col();
								if (col <= 72)
								{
									col += 32;
								}

								if (col >= 97 && col <= 104)
								{
									c1 = col - 96;
									valid = 0;
								}
								else
								{
									valid = 1;
									wcout << "Invalid. Please enter column again: " << endl;
								}
							} while (valid);

							//taking row

							wcout << "Enter the row:" << endl;
							do
							{
								r1 = get_row();
								r1 = 9 - r1;
								if (r1 > 8 || r1 < 1)
								{
									wcout << "Invalid. Please enter row again: " << endl;
								}
							} while (!(r1 <= 8 && r1 >= 1));
						} while (chess_board.get_pieces()[r1 - 1][c1 - 1] == NULL || chess_board.get_pieces()[r1 - 1][c1 - 1]->get_Player() != player);
						//showing valid moves for that piece
						chess_board.store_moves(r1 - 1, c1 - 1);

						if (chess_board.get_v_moves(r1 - 1, c1 - 1) == 0)
						{
							wcout << endl << "No Valid Moves Possible for this Piece.\n";
							change = 1;
						}
						else
						{
							wcout << endl << "0) Proceed \n1) Change Piece." << endl;
							change = get_op();
						}

					} while (change);

					//choosing where to move the piece
					do
					{
						wcout << "Enter the coordinates where you want to move the piece to: " << endl;
						//taking column
						wcout << "Enter the column:" << endl;
						do
						{
							col = get_col();
							if (col <= 72)
							{
								col += 32;
							}
							if (col >= 97 && col <= 104)
							{
								c2 = col - 96;
								valid = 0;
							}
							else
							{
								valid = 1;
								wcout << "Invalid. Please enter column again: " << endl;
							}
						} while (valid);
						//taking row
						wcout << "Enter the row:" << endl;
						do
						{
							r2 = get_row();
							r2 = 9 - r2;
							if (r2 > 8 || r2 < 1)
							{
								wcout << "Invalid. Please enter row again: " << endl;
							}
						} while (!(r2 <= 8 && r2 >= 1));

						flag = chess_board.move(r1 - 1, c1 - 1, r2 - 1, c2 - 1, player);

						if (flag == 0)
						{
							wcout << "Invalid move. Please enter the coordinates where you want to move the piece to again." << endl;
						}

					} while (flag == 0);
				} while (flag == 1);

				//changing turns
				if (player == 0)
				{
					player = 1;
				}
				else
				{
					player = 0;
				}

				if (flag != 4)
				{
					chess_board.display();
				}
				if (flag == 4)
				{
					wcout << "\nCheckmate!\n";
				}
				if (flag == 5)
				{
					wcout << "\nDraw!\n";
				}

				save_state(chess_board.get_pieces(), file_name);

			} while (flag != 4 && flag != 5);
		}
	}
	else if (user == 2)
	{


	
	Admin admin, fileadmin;

	char name[50];
	char password[50];

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
	wcout << "											 Enter Admin Name: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin.getline(name, 50);
	cin.ignore(INT_MAX, '\n');
		
	
	bool valid = true;

	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "											 Enter PASSWORD (Minimum 6 characters) " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin.getline(password, 50);
		cin.ignore(INT_MAX, '\n');
		if (strlen(password) < 6)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			wcout << "						Invalid password \n Password must be atleast 6 characters long\n ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			valid = false;
		}
		else
		{
			valid = true;
		}
		} while (!valid);

		do
		{
			valid = false;

			admin.set_name(name);
			admin.set_password(password);

			ifstream in("data_admin.dat");
			if (!in)
			{
				wcout << "											 Admin Doesn't Exist " << endl;
			}

			in.read((char*)(&fileadmin), sizeof(fileadmin));
			if (strcmp(fileadmin.get_name(), admin.get_name()) == 0)
			{
				if (strcmp(fileadmin.get_name(), admin.get_name()) == 0)
				{
					valid = true;
				}
			}

			if (valid == false)
			{
				wcout << "											 Invalid Credentials " << endl;


			}

		} while (!valid);

		int admin_op;
		int id;

		do
		{
			admin_op = admin_menu();


			switch (admin_op)

			{
			case 1:
				user_list();
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
				wcout << "											 Enter Player ID: " << endl;
				cin >> id;
				searchPlayer(id);
				break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
				wcout << "													Invalid Option" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			}
		} while (admin_op < 1 || admin_op > 2);
	}
}






