#pragma once
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include<iostream>
#include <io.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int board_row = 8;
const int board_col = 8;
void buddy_display();
class Piece
{
public:
	virtual void valid_move(Piece*** const boardt, int** p_array = NULL, int p_moves = 0) = 0;

	static int captured_whites, captured_blacks;
	static char* captured_whites_array;
	static char* captured_blacks_array;
	bool get_Player();
	int get_x_position();
	int get_y_position();
	bool check_check(Piece*** const board, int** p_moves, int p, bool x);
	int** get_valid_move_array();
	int get_v_moves();
	void set_x(int x_position);
	void set_y(int y_position);
	void draw_moves(Piece*** const pieces);
	char getName() const;
	void set_player(bool p);

	void set_name(char n);

	void set_v_moves(int v);


	void set_valid_move_player(int** v = NULL);
	


protected:
	int** valid_move_array;
	int x_position;
	int y_position;
	int v_moves = 0;
	bool Player;
	char name;


};

