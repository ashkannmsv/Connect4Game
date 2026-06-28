#include <stdio.h>
#include "game_logic.h"

int main() {

    printf("Welcome to Connect Four!\n");
    printf("enter the row and column of the board (row >= 4 , col < 12)\n");
    
    int row, col;
    while (1) {
        printf("enter the number of rows: \n");
        scanf("%d", &row);
        printf("enter the number of columns: \n");
        scanf("%d", &col);

        if (row < 4 || col >= 12) {
            printf("invalid board dimensions. please enter row >= 4 and col < 12.\n");
            continue;
        } else {
            break;
        }
    }
    
    int board_size[2] = {row , col};
    int board [board_size[0]][board_size[1]];

    clear_board(row , col , board);

    // player chooser
    printf("which player's turn? (1 or 2): ");
    int player;
    scanf("%d" , &player);

    while (!is_board_full(row , col , board))
    {
        for (int i=0 ; i<col ; i++)
            printf("%d " , i+1);
        printf("\t columns num\n-----------------------------\n");
        print_board(row , col , board);
        printf("\n");

        while (player != 1 && player != 2) {
            printf("the number you entered is not valid. please enter 1 or 2 :\n");
            scanf("%d" , &player);
        }


        //input
        int entered_num;
        printf("player %d , please enter number: " , player);
        scanf("%d" , &entered_num);
        entered_num--;
        printf("\n\n");
        if (entered_num < 0 || entered_num >= col) {
            printf("the number you entered is not valid. please enter a number between 1 to %d :\n" , col);
            continue;
        }
        
        if (board[0][entered_num] != 0) {
            printf("the column you entered is full. please enter another column :\n");
            continue;
        }
        input(row , col , board , player , entered_num);

        //calc
        if (is_winner(row , col , board)){
            print_board(row , col , board);
            printf("\n");
            printf("player %d is the winner!\n" , player);
            break;
        }
        
        if(player == 1) 
            player = 2;
        else
            player = 1;
        

        //print
        for (int i=0 ; i<col ; i++)
            printf("%d " , i+1);

        printf("\t columns num\n-----------------------------\n");
        print_board(row , col , board);
        

        printf("\n\n\n");
    }
    
    if (is_board_full(row , col , board)) {
        printf("the board is full. it's a draw!\n");
    }

    return 0;
}