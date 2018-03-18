#include <stdio.h>
#include <string.h>
#include "1.h"
//函数
int create_board();
int print_board();
int play_game(int, int);
int real_move(int, int, char);
int Player_Move(char);
int updata_4D(int, int);
extern int AI_Move(char);
extern int load_situa();
extern int try_move(int, int);
extern int print_4D();
//变量
char board[SIZE][SIZE*2+1];
char four_dimen[4][20];
//主函数
int main(){
	load_situa();
	create_board();
	print_board();
	printf("\n先输入数字坐标，空格后,再输入字母坐标\n你的棋将显示为X，电脑的显示为O\n");
	play_game(0,1);
	while (1);
	return 0;
}
//
int create_board() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < 2*SIZE; j+=2) {
			board[i][j] = '+';
			board[i][j + 1] = ' ';
		}
	}
	return 0;
}
int print_board() {
	printf("\n  ");
	for (int i = 0; i < 19; ++i)
		printf("%c ", i+65);
	printf("\n");
	for (int i = 0; i < 19; ++i) {
		if (i < 10)
			printf(" ");
		printf("%d",i);
		printf("%s\n", board[i]);
	}
	return 0;
}
int play_game(int P_A, int turn) {
	char color[2] = {BLACK, WHILE};
	if (P_A) {
		while (1) {
			if (turn > 0)
				Player_Move(color[0]);
			else
				Player_Move(color[1]);
			turn *= -1;
		}
	}
	else {
		while (1) {
			if (turn > 0)
				Player_Move(color[0]);
			else
				AI_Move(color[1]);
			turn *= -1;
		}
	}
}
int real_move(int x, int y, char color) {
	board[x][y * 2] = color;
	print_board();
	return 0;
}
int Player_Move(char color) {
	int x;
	char y;
	scanf("%d %c", &x, &y);
	y = y - 65;
	if (ILLEGA_PLA)
		return Player_Move(color);
	else {
		real_move(x, y, color);
		return 0;
	}
}
int updata_4D(int x, int y) {
	int i, j;
	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE - 1; ++j) {
			four_dimen[i][j] = '+';
		}
		four_dimen[i][j + 1] = 0;
	}
	for (i = 0; i < SIZE; ++i)
		four_dimen[0][i] = board[x][2 * i];
	for (i = 0; i < SIZE; ++i)
		four_dimen[1][i] = board[i][2 * y];
	if (y>x) {
		for (i = 0; i < SIZE - (y - x); ++i)
			four_dimen[2][i] = board[i][2 * (y - x + i)];
		four_dimen[2][SIZE - (y - x)] = 0;
		if (x + y < 18)
			for (i = 0; i < x + y + 1; ++i)
				four_dimen[3][i] = board[i][2 * (x + y - i)];
		else
			for (i = 0; i < x + y + 1; ++i)
				four_dimen[3][i] = board[x + y - 18 + i][2 * (18 - i)];
		four_dimen[3][x + y + 1] = 0;
	}
	else {
		for (i = 0; i < SIZE - (x - y); ++i)
			four_dimen[2][i] = board[(x - y) + i][2 * i];
		four_dimen[2][SIZE - (x - y)] = 0;
		if (x + y < 18)
			for (i = 0; i < x + y + 1; ++i)
				four_dimen[3][i] = board[i][2 * (x + y - i)];
		else
			for (i = 0; i < x + y + 1; ++i)
				four_dimen[3][i] = board[x + y - 18 + i][2 * (18 - i)];
		four_dimen[3][x + y + 1] = 0;
	}
	return 0;
}