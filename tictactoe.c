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

bool checkDraw(char board[3][3]){
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            if(board[r][c] == ' '){
                return 0;
            }
        }
    }

    return 1;

}

int main()
{
    //welcome
    printf("--Welcome to Tic-Tac-Toe!--\n");
    printf("\n");

    char player = 'X';

    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    printBoard(board);
    
    //start the game
    
    bool gameOver = 0;
    bool turn = 0;
    
    
    while(!gameOver){
        
        if(!turn){
            player = 'X';
        }
        else{
            player = 'O';
        }

        printf("%c's move (row and column from 0 to 2): ", player);
        scanf("%d %d", &row, &col);
        if(board[row][col] == ' ' && row <=2 && col <= 2){
                board[row][col] = player;
                printf("\n");
                printBoard(board);
                turn = !turn;
        }

        else{
            printf("Invalid move!\n");
            continue;
        }

        gameOver = checkWin(board, player) || checkDraw(board);    
    
    }

    if(checkWin(board, player)){
        printf("%c wins!\n", player);
    } 
    else{
        printf("Draw!");
    }   
    
    return 0;

}