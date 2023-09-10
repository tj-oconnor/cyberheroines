#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

__attribute__((constructor)) void ignore_me() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

char board[3][3];

void win() {
   FILE *fp;
   char flag[255];
   fp = fopen("flag.txt", "r");
   fscanf(fp, "%s", flag);
   printf("<<< Congratulations: %s\n", flag );
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void main() {
    // Initialization

    int currentPlayer = 1;
    int row, col;
    char playerSymbols[2] = {'X', 'O'};

    char playAgain;

    printf("------------------------------\n");
    printf("Tic Tac Pwn v%li              \n",rand);
    printf("------------------------------\n");

    do {
        for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' '; // Initialize the board with empty spaces
        }
        }

        printf("Player 1: Choose your symbol ('X' or 'O') >>> ");
        scanf(" %c", &playerSymbols[0]);
        playerSymbols[1] = (playerSymbols[0] == 'X') ? 'O' : 'X';


        while (true) {
            displayBoard();

            printf("Player %d, enter row (0-2) and column (0-2) to place your symbol >>> ", currentPlayer);
            scanf("%d %d", &row, &col);

            board[row][col] = playerSymbols[currentPlayer - 1];


            if (checkWin(board, playerSymbols[currentPlayer - 1])) {
                displayBoard();
                printf("<<< Player %d wins!\n", currentPlayer);
                break;
            } else if (checkDraw(board)) {
                displayBoard();
                printf("<<< It's a draw!\n");
                break;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

        printf("Do you want to play again? (Y/N) >>> ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');
    puts("Goodbye!\n");
    exit(0);
}
