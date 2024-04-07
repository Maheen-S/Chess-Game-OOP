#pragma once
#pragma warning(disable : 4996)
#include "Board.h"
#include "Temp_Piece.h"
#include "Admin.h"

using namespace std;

int get_row()
{
	int r = 0;
	cin >> setw(1) >> r;

	//Error check
	while (!cin.good())
	{
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		wcout << "												 ERROR: Wrong input! Try again. " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "																 Enter row: " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> setw(1) >> r;
	}
	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return r;
}

char get_col()
{
	char c;
	cin >> setw(1) >> c;

	//Error check
	while (!cin.good())
	{
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		wcout << "													 ERROR: Wrong input! Try again. " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "														 Enter column: " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> setw(1) >> c;
	}
	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return c;
}

bool get_op()
{
	bool o = 0;
	cin >> setw(1) >> o;

	//Error check
	while (!cin.good())
	{
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		wcout << "													ERROR: Wrong input! Try again." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "Press 0 to proceed or press 1 to change the piece.  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> setw(1) >> o;
	}
	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return o;
}

long long int get_CNIC()
{
	long long int cnic;
	bool valid = false;

	do
	{
		cin >> cnic;

		while (!cin.good())
		{
			//Reporting problem
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			wcout << "														ERROR: Wrong input! Try again. " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			//Clear stream
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			//Getting input again
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			wcout << "														Enter CNIC (without dashes): " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cin >> cnic;
		}

		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		long long int a = cnic;
		int d_count = 0;
		while (a > 0)
		{
			a = a / 10;
			d_count++;
		}
		if (d_count != 13)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			wcout << "											  CNIC must be 13 digits long.  " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}
		else
		{
			valid = true;
		}

	} while (!valid);


	return cnic;

}

//Display Buddy's Chess
void display_buddy()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "						    ================================================================================================================" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "						    _____                ______      ______                 __   _____     _____   _    _  ______   _____  _____     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "						    |  __ \\  | \\     / | |  ___  \\   |  ___  \\   \\\\      // |__| / ____|   |   ___ | |  | |   ____| / ____ / ____|     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "						    | |__) | | |     | | | |   \\  \\  | |   \\  \\   \\\\    //     /  (___     | |     | |__| |  |__   | (___ | (___       " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "						    |  __ (  | |     | | | |    )  ) | |    )  )   \\\\||//     /  \\___ \\    | |     |  __  |   __|  \\ ___ \\ \\___ \\     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "						    | |__) | | \\_____/ | | |___/  /  | |___/  /      ||          ____) |   | |____ | |  | |  |____  ____)  ____) |     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "						    |  ___/   \\_______/  |_______/   |_______/       ||           _____/   \\_____  |_|  |_|  ______| _____/ _____/     " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "						  =================================================================================================================" << endl;






	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int display_user_menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << '.';

	int user;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "\n\n\t\t\t\t\t\t\t\t\t\t_       P L E A S E   S E L E C T   M O D E       _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n\n   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\t\t\t\t\t\t\t\t\t\t\t1._     P L A Y E R   M O D E   _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n\n   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\t\t\t\t\t\t\t\t\t\t\t2._     A D M I N   M O D E     _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "\n";
	cin >> user;

	while (!cin.good())
	{
		system("CLS");
		display_buddy();
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\tERROR: WRONG INPUT! TRY AGAIN." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n";

		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << '.';

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		wcout << "\n\n\t\t\t\t\t\t\t\t\t\t_       P L E A S E   S E L E C T   M O D E       _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\t\t\t\t\t\t\t\t\t\t\t1._     P L A Y E R   M O D E   _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\t\t\t\t\t\t\t\t\t\t\t2._     A D M I N   M O D E     _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		wcout << "\n";

		cin >> user;
	}

	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return user;
}

int admin_menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << '.';

	int admin;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "\n\n\t\t\t\t\t\t\t\t\t\t_       P L E A S E   S E L E C T   M O D E       _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n\n      ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\t\t\t\t\t\t\t\t\t\t\t1._     S T A T S   _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n\n   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\t\t\t\t\t\t\t\t\t\t\t2._     SEARCH PLAYER     _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "\n";
	cin >> admin;

	while (!cin.good())
	{
		system("CLS");
		display_buddy();
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		wcout << "\n\n\t\t\t\t\t\t\t\t\t\t_       P L E A S E   S E L E C T          _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\t\t\t\t\t\t\t\t\t\t\t1._			S T A T S   _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\t\t\t\t\t\t\t\t\t\t\t2._     SEARCH PLAYER     _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		wcout << "\n";
		cin >> admin;
	}

	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return admin;
}

int login_register()
{
	int op;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\n\t\t\t\t\t\t\t\t\t\t\t\t     L O G I N    ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".\n\n   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "\t\t\t\t\t\t\t\t\t\t\t      R E G I S T R A T I O N    ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl << endl;
	cin >> op;

	while (!cin.good())
	{
		system("CLS");
		display_buddy();
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\tERROR: WRONG INPUT! TRY AGAIN." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n";

		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << '.';

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		wcout << "\n\n\t\t\t\t\t\t\t\t\t\t\t1._      P L A Y E R   M O D E   _";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\n\t\t\t\t\t\t\t\t\t\t\t\t     L O G I N    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".\n\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << "\t\t\t\t\t\t\t\t\t\t\t      R E G I S T R A T I O N    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		wcout << endl << endl;
		cin >> op;
	}

	//Clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return op;
}

void login(Player& p)
{
	long long cnic, a;
	bool valid = false;
	char password[50];
	Player temp;

	do
	{


		do
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			wcout << endl << endl;
			wcout << "												  Enter CNIC   " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cnic = get_CNIC();
			a = cnic;
			int d_count = 0;
			while (a > 0)
			{
				a = a / 10;
				d_count++;
			}
			if (d_count != 13)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
				wcout << "												  Invalid CNIC!" << endl;
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

		valid = false;
		p.set_cnic(cnic);
		p.set_password(password);

		ifstream in("data_user.dat");

		while (!in.eof())
		{
			in.read((char*)(&temp), sizeof(temp));

			if (temp.get_cnic(), p.get_cnic())
			{
				if (strcmp(temp.get_password(), p.get_password()) == 0)
				{
					valid = true;
					break;
				}
			}
		}

		if (valid)
		{
			p = temp;

			p.set_possible_moves_array(NULL);
			p.set_possible_moves(0);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			wcout << "											   Invalid CNIC or Password.   \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}


	} while (!valid);
}

void registration(Player& p)
{
	char name[50];
	char password[50];
	long long cnic, a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
	wcout << "												  Enter Your Name " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cin.getline(name, 50);
	cin.ignore(INT_MAX, '\n');
	bool valid = false;

	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "												  Enter PASSWORD " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin.getline(password, 50);
		cin.ignore(INT_MAX, '\n');
		if (strlen(password) < 6)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			wcout << "											Invalid password \n Password must be atleast 6 characters long \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			valid = false;
		}
		else
		{
			valid = true;
		}
	} while (!valid);


	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		wcout << "												    Enter CNIC  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cnic = get_CNIC();
		a = cnic;
		int d_count = 0;
		while (a > 0)
		{
			a = a / 10;
			d_count++;
		}
		if (d_count != 13)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			wcout << "												  Invalid CNIC ! " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			valid = false;
		}
		else
		{
			valid = true;
		}
	} while (!valid);

	//storing registeration data

	Player temp;
	ofstream out("data_user.dat", ios::app);
	temp.set_name(name);
	temp.set_cnic(cnic);
	temp.set_password(password);
	temp.set_check(0);
	temp.set_possible_moves(0);
	temp.set_possible_moves_array(NULL);

	out.seekp(0, ios::end);

	int number_of_players = out.tellp() / (sizeof(temp));

	int id = number_of_players;

	temp.set_id(id);

	out.write((char*)&temp, sizeof(temp));

	out.close();
}

int display_main_menu()
{
	int op;
	
	wcout << "	  										       ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout <<"Select one Option : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "											          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "1) New Game. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "					  						          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "2) Load Game. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "									  		          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "3) Stats. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "											          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "4) Rules. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "											          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "5) How To Play . ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "											          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "6) About Us . ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << "											          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "7) Exit ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	

	cin >> setw(1) >> op;

	while (!cin.good())
	{
		//Reporting problem
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		wcout << "															ERROR: Wrong input! Try again." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//Clear stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//Getting input again

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		wcout << "														Select one Option: ";
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										1) New Game. " ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										2) Load Game. " ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										3) Stats. " ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										4) Rules. " ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										5) How To Play . ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										6) About Us ." ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		wcout << ".";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
		wcout << endl << "										7) Exit" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> setw(1) >> op;
	}

	if (op < 1 || op >7)
	{
		display_main_menu();
	}

	return op;

}


void how_to_play()
{
	//How to Play
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "											HOW TO PLAY BUDDY'S CHESS  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "										_     The Chessboard is your Kingdom!    _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;
	wcout << endl;


	//How to Play
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "										_       T H E    C H E S S M E N          _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "										_  Your army and that of your opponent    _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;
	wcout << endl;
	wcout << "\t\t\t\t\t						 Each side has 8 Pawns. \n";
	wcout << "\t\t\t\t							 Each side has 2 Knights. \n";
	wcout << "\t\t\t\t\t						Each side has 2 Bishops. \n";
	wcout << "\t\t\t\t\t						 Each side has 2 Rooks. \n";
	wcout << "\t\t\t\t\t						 Each side has 1 Queen. \n";
	wcout << "\t\t\t\t\t						 Each side has 1 King. \n";
	wcout << "\t\t\t\t				     		Each side has 16 men, 8 pieces and 8 pawns \n";
	wcout << endl;
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "										_        S T E P - W I S E   G U I D E        _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "								_    The blunders are all there on the board, waiting to be made...    _";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;

	wcout << "							The board includes the numbers 1 - 8 along the right edge and the letters 'A' - 'H' along \n							the bottom of the board. \n"
		<< "							We can use the combination of one letter and one number to describe each square on the chessboard. ";
	wcout << endl;
	wcout << endl;

	wcout << "								Step I: Enter your column.     \n";
	wcout << "								Step II: Enter your row.  \n";
	wcout << "								Step III: All possible moves of your selected piece will be shown. \n";
	wcout << "								Step IV: Press 0 to proceed moving the same piece at one of the positions. \n";
	wcout << "								Step V: If you proceeded with your initially selected piece (pressed '0' at prompt): \n";
	wcout << "									Step V.I: Enter the Column where you want to move your piece.   \n";
	wcout << "									Step V.II: Enter the Row where you want to move your piece.   \n";
	wcout << "								Step VI: Press 1, if you wish to change your piece. \n";
	wcout << "									Step VI.I: Repeat from Step I. \n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	wcout << "								Note: You will be given a Prompt if you enter an invalid position. ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;
}

void rules()
{
	//Rules 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "											 RULES OF BUDDY'S CHESS  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "										Chess is not like life... it has rules! ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;

	wcout << "						1. White always moves first, and players alternate turns. \n";
	wcout << "						2. Players can only move one piece at a time, except when castling.(explained later) \n";
	wcout << "						3. Players cannot take or move through their own pieces. \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						4. Pawn - soul of the game: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 4.1. Pawns only move forward. On the first move a pawn can move one or two spaces, every subsequent move \n 	   			  				    can only be one space.\n";
	wcout << "							 4.2. Pawns move diagonally to take opponents.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						5. Rooks: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 5.1. Rooks move in a continuous line forwards, backwardsand & side - to - side.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						6. Knights: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 6.1. Knights are the only pieces that can 'jump' over other pieces. \n "
		<< "							 6.2. Unlike other pieces they are not blocked if there are pieces between themand their destination square. \n";
	wcout << "							 6.3. It moves two spaces in a direction forward, backward or side-to-side, and one space at a right turn. \n 	   			  				     (Moves in a 'L') \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						7. Bishops : \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 7.1 Bishops move in continuous diagonal lines in any direction. \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						8 Queen : \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 8.1 The queen moves in continuous diagonal and straight lines. Forward, backward and side-to-side.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	wcout << "						9. King: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							 9.1. The king can move in any direction, one square at a time. \n";
	wcout << "							 9.2. King should not be in check (being attacked by other player) \n";
	wcout << endl;
	wcout << endl;

	wcout << endl;
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 192);
	wcout << "										_       S P E C I A L   M O V E S       _ ";
	//wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						PAWN PROMOTION: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							1.1. If a pawn reaches the opposite side of the board, it is promoted to a higher piece(except king). \n 	   			  				    There is no limit to how many pawns can be promoted.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << endl;
	wcout << "						2. CASTLING: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							Castling is the only move that allows two pieces to move during the same turn.\n"
		<< "							During castling a king moves two spaces towards the rook that it will castle with, and the rook jumps to the \n 							other side.\n"
		<< "							The king can castle to either side as long as :\n"
		<< "							2.1. The king has not moved.\n"
		<< "							2.2. The king is not in check.\n"
		<< "							2.3. The king does not move through or into check.\n"
		<< "							2.4. There are no pieces between the king and castling - side rook.\n"
		<< "							2.5. The castling - side rook has not moved.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						3. EN PASSANT:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							3.1. Special movement for pawns attacking pawns.It only applies if your opponent moves a pawn two spaces, and \n 							 its destination space is next to your pawn. \n"
		<< "							3.2. You can take the opposing piece by moving forward-diagonal to your pawn's attacked square. \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						4. CHECK: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							4.1. A king is in check when an opponent's piece is in a position that can attack the king. \n"
		<< "							4.2. A player must move their king out of check, block the check or capture the attacking piece.\n"
		<< "							4.3. A player cannot move their king into check.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						5. CHECKMATE: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							5.1. A king is in checkmate if it is in check, the opponent's piece that has the king in check cannot be captured, \n 							 the check cannot be blocked, and the king cannot move to a square that is not under attack.\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						6. STALEMATE:\n ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << "							6.1. 'Stalemate' is a tie. It is achieved if there are no legal moves for a player to make.\n";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	wcout << "						7. The best feature of Buddy's Chess.. We will autosave your game after every move!!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;

	wcout << endl;
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "												Now you know the Rules";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "							The blunders are all there on the board, waiting to be made. So grab a Chess buddy and find out for yourself!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void stats(Player &p0, Player &p1)
{
	ifstream in("date_user.dat");
	Player tempPlayer;

	while (!in.eof())
	{
		in.read((char*)&tempPlayer, sizeof(tempPlayer));
		if (p0.get_id() == tempPlayer.get_id() || p1.get_id() == tempPlayer.get_id())
		{
			tempPlayer.Display();
		}
	}
}

void About_us()
{
	//About Us & our game
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	wcout << "											 RULES OF BUDDY'S CHESS  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
	wcout << "										Chess is not like life... it has rules! ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	wcout << "						Buddy's Chess was created by five buddies who wanted to do nothing but bring joy into your otherwise miserable life. \n";
	wcout << endl;
	wcout << endl;
	wcout << "								Inspired by 'Chatraunga', later called 'Shatranj' in Sanskrit & Chess in English, \n										the five buddies created their version, called Buddy's Chess. \n";
	wcout << endl;
	wcout << "								 Chess was invented long ago. the names we use for the pieces date from the Middle Ages. \n";
	wcout << "							In those days kingdoms were ruled by Kings and Queens.They lived in castles & had Bishops to advice them. \n";
	wcout << "										 They also had brave Knights to defend them. \n";
	wcout << "										Even the peasants helped to defend the kingdom. \n";
	wcout << endl;
	wcout << "									There were places to play online, but none of them felt like home.\n";
	wcout << "					 We imagined a site where people could build their chess home online and all in one place to play in a safe and friendly environment, \n										  in presence of their buddies & save their games. \n";

	wcout << endl;
	wcout << "										   We belive that you never lose when you learn! \n";
	wcout << "					Life & chess are both about learning, growing, experimenting, failing & then getting back up again with greater knowledge & understanding. \n";
	wcout << "								We believe in fun, smiles, laughter, and in creating enjoyable experiences for everyone. \n";
	wcout << "						Chess can be pure joy! The beauty of the game and the pure satisfaction of moving chess pieces around a board is exhilarating! \n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	wcout << endl;
	wcout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	wcout << "										Experience the ancient empires by playing the game!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	wcout << ".";
	wcout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	wcout << endl;
	wcout << endl;
	wcout << endl;
	wcout << endl;
 }

//Saving State of the Game after each move
void save_state(Piece*** const board, string filename)
{
	ofstream temp("save.dat", ios::trunc);
	temp.close();

	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			ofstream out(filename, ios::app);
			if (!out)
			{
				wcout << "Unable to open file!\n";
			}
			else
			{

				if (board[i][j] != NULL)
				{
					Temp_Piece t;
					t = board[i][j];
					out.write((char*)(&t), sizeof(t));
					out.seekp(0, ios::end);
					
				}
			}


			out.close();
		}
	}

}


//Loading previously saved state

void load_state(Piece*** p, string filename)
{
	bool flag = true;
	ifstream in(filename, ios::binary);

	if (!in)
	{
		wcout << "No Previously Saved State Exists.";
	}
	else
	{
		while (!in.eof())
		{
			Temp_Piece p1;
			for (int i = 0; i < board_row; i++)
			{
				for (int j = 0; j < board_col; j++)
				{
					if (flag == true)
					{
						in.read((char*)&p1, sizeof(p1));
						flag = false;
					}

					if ((i == p1.get_x_p()) && (j == p1.get_y_p()))
					{
						switch (p1.get_name())
						{
						case 'k':
							p[p1.get_x_p()][p1.get_y_p()] = new King(i, j, 1);
							flag = true;
							break;
						case 'r':
							p[p1.get_x_p()][p1.get_y_p()] = new Rook(i, j, 1);
							flag = true;
							break;
						case 'b':
							p[p1.get_x_p()][p1.get_y_p()] = new Bishop(i, j, 1);
							flag = true;
							break;
						case 'n':
							p[p1.get_x_p()][p1.get_y_p()] = new Knight(i, j, 1);
							flag = true;
							break;
						case 'q':
							p[p1.get_x_p()][p1.get_y_p()] = new Queen(i, j, 1);
							flag = true;
							break;
						case 'p':
							p[p1.get_x_p()][p1.get_y_p()] = new Pawn(i, j, 1);
							flag = true;
							break;
						case 'K':
							p[p1.get_x_p()][p1.get_y_p()] = new King(i, j, 0);
							flag = true;
							break;
						case 'R':
							p[p1.get_x_p()][p1.get_y_p()] = new Rook(i, j, 0);
							flag = true;
							break;
						case 'B':
							p[p1.get_x_p()][p1.get_y_p()] = new Bishop(i, j, 0);
							flag = true;
							break;
						case 'N':
							p[p1.get_x_p()][p1.get_y_p()] = new Knight(i, j, 0);
							flag = true;
							break;
						case 'Q':
							p[p1.get_x_p()][p1.get_y_p()] = new Queen(i, j, 0);
							flag = true;
							break;
						case 'P':
							p[p1.get_x_p()][p1.get_y_p()] = new Pawn(i, j, 0);
							flag = true;
							break;
						}

						p[p1.get_x_p()][p1.get_y_p()]->set_name(p1.get_name());
						p[p1.get_x_p()][p1.get_y_p()]->set_x(p1.get_x_p());
						p[p1.get_x_p()][p1.get_y_p()]->set_y(p1.get_y_p());
						p[p1.get_x_p()][p1.get_y_p()]->set_player(p1.get_player());
						p[p1.get_x_p()][p1.get_y_p()]->set_v_moves(0);
						p[p1.get_x_p()][p1.get_y_p()]->set_valid_move_player(NULL);
					}
					else
					{
						p[i][j] = NULL;
					}

				}
			}
		}
	}
	in.close();
}

void user_list()
{
	ifstream in("data_user.dat");
	Player tempPlayer;

	while (!in.eof())
	{
		in.read((char*)&tempPlayer, sizeof(tempPlayer));
		tempPlayer.Display();
	}
}

void searchPlayer(int id)
{
	bool found = false;
	ifstream in("data_user.dat");
	Player tempPlayer;
	

	while (!in.eof())
	{
		in.read((char*)&tempPlayer, sizeof(tempPlayer));
		if (id == tempPlayer.get_id() || id == tempPlayer.get_id())
		{
			
			tempPlayer.Display();
			found = true;
			break;
		}
	}

	if (found == false)
	{
		wcout << "Player not found.";
	}
}