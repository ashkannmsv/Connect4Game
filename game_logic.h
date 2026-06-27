#ifndef GAME_LOGIC
#define GAME_LOGIC

void clear_board(int row , int col , int board[row][col]);
int is_winner(int row , int col , int board[row][col]);
void print_board(int row , int col , int board[row][col] );
int is_board_full(int row , int col , int board[row][col]);
void input(int row , int col , int board[row][col]  ,int user ,int num);


#endif