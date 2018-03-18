#define SIZE 19
#define BLACK 'X'
#define WHILE 'O'
#define ILLEGA_PLA (board[x][y*2] == BLACK || board[x][y*2] == WHILE || x > 18 || y > 18)
#define NUM_SITUA 31
typedef struct Situa {
	char name[20];
	int score;
}situa;
typedef struct Move {
	int x, y, grade;
}move;