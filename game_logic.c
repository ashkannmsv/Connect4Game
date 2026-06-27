#include <stdio.h>
#include "game_logic.h"

void clear_board(int row , int col , int board[row][col]) {
    for (int i=0 ; i<row ; i++) {
        for (int j=0 ; j<col ; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int row , int col , int board[row][col] ) {
    for (int i=0 ; i<row ; i++) {
        for (int j=0 ; j<col ; j++) {
            printf("%d " , board[i][j]);
        }
        printf("\n");
    }
}

int is_board_full(int row , int col , int board[row][col]) {
    for (int j=0 ; j<col ; j++) {
        if (board[0][j] == 0) return 0;
    }
    return 1;
}

void input(int row , int col , int board[row][col]  ,int user ,int num) {
    for(int i = row-1 ; i>=0 ; i--) {
        if (board[i][num] == 0) {
            board[i][num] = user;
            break;
        }
        if (i == 0) {
            printf("Column is full\n");
        }
    }
}

int is_winner(int row , int col , int board[row][col]) {
    for (int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++) {
            if (board[i][j] == 0) continue;
            
            int user = board[i][j];

            // 0000
            // 0000
            // 1111
            // 0000

            for(int k=1; k<=3 ; k++){
                if (j+k >= col) break;
                if (board[i][j+k] != user) break;
                if (k == 3) return 1;
            }

            // 0100
            // 0100
            // 0100
            // 0100

            for(int k=1; k<=3 ; k++){
                if (i+k >= row) break;
                if (board[i+k][j] != user) break;
                if (k == 3) return 1;
            }

            // 0001
            // 0010
            // 0100
            // 1000

            for(int k=1; k<=3 ; k++){
                if (j+k >= col || i+k >= row) break;
                if (board[i+k][j+k] != user) break;
                if (k == 3) return 1;
            }

            // 1000
            // 0100
            // 0010
            // 0001

            if (i >= 3 && j <= col - 4) {
                for(int k=1; k<=3 ; k++){
                    if (board[i-k][j+k] != user) break;
                    if (k == 3) return 1;
                }
            }
        }
    }

    return 0;
}

