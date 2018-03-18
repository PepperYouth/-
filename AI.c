#include "1.h"
#include <stdio.h>
#include <string.h>
extern char board[SIZE][SIZE * 2 + 1];
extern char four_dimen[4][20] = {'+'};
situa all_situa[NUM_SITUA];
move all_move[400];
extern int real_move(int,int,char);
extern int updata_4D(int, int);
int try_move(int x, int y) {
	if (ILLEGA_PLA)
		return 0;
	else {
		board[x][y * 2] = 'Q';
		return 1;
	}
}
int calcu_grade(situa *all_situa) {
	int Grade = 0;
	for (int i = 0; i < NUM_SITUA; i++) {
		for (int j = 0; j < 4; ++j) {
			if (strstr(four_dimen[j], all_situa[i].name)!=NULL) {
				Grade += all_situa[i].score;
			}
		}
	}
	return Grade;
}
int rank(move* all_move) {
	for (int i = 0; i < 400; ++i) {
		if (all_move[i].grade > all_move[0].grade) {
			all_move[0] = all_move[i];
		}
	}
	return 0;
}
int AI_Move(char color) {
	int i = 0;
	for (int x = 0; x < SIZE; ++x) {
		for (int y = 0; y < SIZE; ++y) {
			if (try_move(x, y)) {
				all_move[i].x = x;
				all_move[i].y = y;
				updata_4D(x, y);
				all_move[i].grade = calcu_grade(all_situa);
				++i;
				board[x][y * 2] = '+';
			}
			else {
				all_move[i].x = x;
				all_move[i].y = y;
				all_move[i++].grade = -1;
			}	
		}
	}
	rank(all_move);
	real_move(all_move[0].x, all_move[0].y, color);
	printf("%d %c\n", all_move[0].x, all_move[0].y+65);
	return 0;
}
int print_4D() {
	for (int i = 0; i < 4; i++) {
		printf("%s\n",four_dimen[i]);
	}
	return 0;
}