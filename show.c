#include"chess.h"
void handleShow( int w, int b, int r ) {
    int i, j;

    if(b && !r) {
        printf("%s\n", secondPlayerName) ;
    }
    if(w && r) {
        printf("%s\n", firstPlayerName) ;
    }
    
    printf("board\t");
    if(r) 
    {
        for (i = 7; i > -1; i--)//file labels...
            printf("%c%c", 'a' + i, i == 0 ? '\n' : '\t');
        for (i = 7; i > -1; i--)//table itself
            for (j = 8; j > -1; j--)
                printf("%d%c", j == 8 ? 8 - i : board[i][j - 1], j == 0 ? '\n' : '\t');
    }
    else
    {
        for (i = 0; i < 8; i++)//file labels...
            printf("%c%c", 'a' + i, i == 7 ? '\n' : '\t');
        for (i = 0; i < 8; i++)//table itself
            for (j = 0; j < 9; j++)
                printf("%d%c", j == 0 ? 8 - i : board[i][j - 1], j == 8 ? '\n' : '\t');
    }
    
    if(w && !r) {
        printf("%s\n", firstPlayerName) ;
    }
    if(b && r) {
        printf("%s\n", secondPlayerName) ;
    }
}