#include <stdio.h>
#include <stdbool.h>

void printBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < 2){
            printf("---+---+---\n");
        }    
    }

    printf("\n");
}

bool checkWin(char board[3][3], char player){
    //check rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
    }

    //check cols
    for(int i = 0; i < 3; i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return 1;
        }  
    }

    //check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return 1;
    }
    

    return 0;    
}

int main()
{

    return 0;

}