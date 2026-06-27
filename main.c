#include <stdio.h>
#include "game_logic.h"

int main() {
    
    int row = 7;
    int col = 6;
    int board_size[2] = {row , col};
    int board [board_size[0]][board_size[1]];

    clear_board(row , col , board);

    for (int i=0 ; i<col ; i++)
        printf("%d " , i+1);
    printf("\t columns num\n\n");
    print_board(row , col , board);
    printf("enter the number of column: ");

    while (!is_board_full(row , col , board))
    {
        //input
        int entered_num;
        scanf("%d" , &entered_num);
        entered_num--;
        if (entered_num < 0 || entered_num > col) {
            printf("the number you entered is not valid. please enter a number between 1 to %d :\n" , col);
            continue;
        }
        input(row , col , board , 1 , entered_num);

        //calc
        if (is_winner(row , col , board))    break;
        
        //print
        for (int i=0 ; i<col ; i++)
            printf("%d " , i+1);
        
        printf("\t columns num\n\n");
        print_board(row , col , board);
    }
    

    

    return 0;
}