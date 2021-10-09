#include<stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
#define MAX_COMMAND_TOKEN_LENGTH 6
#define WHITE 1
#define BLACK -1
typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
}square;

typedef enum {
    NONE = 0,
    WHITE_SHORT = 1,
    WHITE_LONG = 2,
    BLACK_SHORT = 4,
    BLACK_LONG = 8
}castle;
extern square board[8][8];
extern int turn;
char firstPlayerName[100] ;
char secondPlayerName[100] ;
char getCommandWord(char command[], int maxLength);
void handleShow( int w, int b, int r );
void handleCapture();
void handleMove( int flag, char* s, char* t );
