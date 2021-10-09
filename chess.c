#include "chess.h"
square board[8][8];
int turn;
static void resetBoard() {
    turn = WHITE;//WHITE moves first
    int i, j;
    for (i = 2; i < 6;i++)
        for (j = 0;j < 8;j++)
            board[i][j] = EMPTY;
    for (j = 0;j < 8;j++) {
        board[1][j] = BLACK * PAWN;
        board[6][j] = WHITE * PAWN;
    }
    board[0][0] = board[0][7] = BLACK * ROOK;
    board[7][0] = board[7][7] = WHITE * ROOK;
    board[0][1] = board[0][6] = BLACK * KNIGHT;
    board[7][1] = board[7][6] = WHITE * KNIGHT;
    board[0][2] = board[0][5] = BLACK * BISHOP;
    board[7][2] = board[7][5] = WHITE * BISHOP;
    board[0][3] = BLACK * QUEEN;
    board[7][3] = WHITE * QUEEN;
    board[0][4] = BLACK * KING;
    board[7][4] = WHITE * KING;
}
char getCommandWord(char command[], int maxLength) {
    char lastCharacter;//either space or new line
    int i;
    for (i = 0; (lastCharacter = getchar()) == ' '; i++);//skip leading white spaces
    if (lastCharacter == '\n') {
        command[0] = '\0';
        return lastCharacter;
    }
    command[0] = lastCharacter;
    for (i = 1; i < maxLength - 1 && (command[i] = getchar()) != ' ' && command[i] != '\n'; i++);
    lastCharacter = command[i];
    command[i] = '\0';
    return lastCharacter;
}

// extern char firstPlayerName[100] ;
// extern char secondPlayerName[100] ;
void main(int argc, char** argv) {
    /*
    * You can access all the command-line arguments here
    * argv[1], argv[2], ...
    * Example of import option: -i d2d4,d7d5,e2e4,d5xe4,Ng1h3,Ke8d7,Qd1d3
    * which is equivalent to a new game started this way:
    * mv d2 d4
    * mv d7 d5
    * mv e2 e4
    * cp d5 e4
    * mv g1 h3
    * mv e8 d7
    * mv d1 d3
    */

   //? defining 4 flags
    int w = 0 ;
    int b = 0 ;
    int r = 0 ;
    int i = 0 ;

    //? importLine will hold the entire import line
    //? s is the source square
    //? t is the target square
    char importLine[5000], s[4], t[4];
    //? move will hold the imported moves one at a time
    //? c is the capture square
    char* move, c;

    //? set the flags properly after I traverse the entire command line argument (char** argv) and then I pass these flags to my handleShow() function 
    int j = 1 ;
    while(argv[j] != NULL)
    {
        if ( strcmp(argv[j], "-w") == 0 )
        {
            //? setting w flag to true
            w = 1 ;

            //? getting the name for the first player.
            strcpy(firstPlayerName, argv[j+1]);
        }
        else if ( strcmp(argv[j], "-b") == 0 )
        {
            //? setting b flag to true
            b = 1 ;

            //? getting the name for the second player.
            strcpy(secondPlayerName, argv[j+1]);
        }
        else if ( strcmp(argv[j], "-r") == 0 )
        {
            //? setting rotate flag to true
            r = 1 ;
        }
        else if ( strcmp(argv[j], "-i") == 0 )
        {
            resetBoard();
            //? setting import flag to true
            i = 1 ;

            //* have to add code here that gets the string "import" and move the pieces acordingly.
            //? getting the hole "import line" inputted by the user, and store it in importLine.
            strcpy(importLine, strtok(argv[++j], " ") ) ;
            printf("importLine = %s\n", importLine) ; // TODO: DELETE
            printf("len importLine = %d\n", strlen(importLine)); // TODO: DELETE

            //? get the first movement or capture from importLine and store it in move.
            move = strtok(importLine, ",") ;
            printf("move = %s\n", move) ; // TODO: DELETE

            //? if move has a capital letter
            if( isupper( move[0] ) != 0 ) 
            {
                move++ ;
            }
            printf("move after removing capital letter: %s\n", move) ; //TODO: DELETE

            //? check if it is a move or capture
            //? if it is a capture
            if( strstr(move, "x") != NULL)
            {
                printf("it is a capture\n"); //TODO: DELETE
            } else { //? if it is a move 
                printf("it is a move\n"); //TODO: DELETE
                //? get the source square
                strncpy(s, &move[0], 2);
                s[2] = '\0' ;
                printf("s = %s\n", s) ;//TODO: DELETE

                //? get the target square
                strncpy(t, &move[2], 2);
                t[2] = '\0' ;
                printf("t = %s\n", t) ;//TODO: DELETE

                //? call handle move
                
            }

            //? go through the entire importLine movements and making the move or capture accordingly
            // for (int c = 0 ; c < strlen(importLine) ; c++)
            // {
            //         //? make the move or capture.
            //         //* get each move and call handle move
            //         handleMove(i, move);
            //         //? get the next movement or capture from importLine.
            //         move = strtok(NULL, ",") ;
            // }	
        }
        j++;
    }

    char command[MAX_COMMAND_TOKEN_LENGTH];
    char lastCharacter;

    //* Have to check if this works!!!!!!
    if(!i)
    {
        resetBoard();
    }

    printf("Start the game using a mv command! Valid commands are quit, show, mv and cp.\n");
    while (1) {//infinite while loop...
        printf(">>");
        lastCharacter = getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH);
        if (strcmp(command, "quit") == 0)//if command === "quit"
            break;
        else if (!strcmp(command, "mv"))//if command == "mv"
        {
            if (lastCharacter == '\n')//mv\n
                printf("Too few arguments for mv command! It must be in the form of mv ai bj.\n");
            else
                handleMove(i, s, t);
        }
        else if (!strcmp(command, "cp"))//if command == "cp"
        {
            if (lastCharacter == '\n')//cp\n
                printf("Too few arguments for cp command! It must be in the form of cp ai bj.\n");
            else
                handleCapture();
        }
        else if (!strcmp(command, "show"))//if command == "show"
        {
            if (lastCharacter != '\n') {//show x\n
                printf("Too many arguments for show command! It must be in the form of show.\n");
                while (getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH) != '\n');//skip the ramainder of the invalid show command...	
            }
            else
                handleShow( w, b, r );
        }
        else {
            printf("invalid command! Your command must start either with quit, show, mv or cp.\n");
            while (lastCharacter != '\n')//skip the remainder of my invalid command...
                lastCharacter = getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH);
        }
    }
}
