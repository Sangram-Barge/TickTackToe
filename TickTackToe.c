#include <stdio.h>
#include <stdlib.h>

#define PLAYER_1 0
#define PLAYER_2 1
#define TRUE 1
#define FALSE 0

void clear();
void draw();
int takeInput();
void begin();
void updateBoard();
void updatePlayer();
int checkWin();

char board[3][3];
int winningBoard[3][3] = {
    {4, 9, 2},
    {3, 5, 7},
    {8, 1, 6}
};
int currentPlayer = PLAYER_1;
char player1[20];
char player2[20];
int boardInput[2];
int moves = 0;

int main() {
    begin();
    draw();
    for(;;) {
        while (!takeInput())
            fprintf(stderr, "invalid input please enter again\n");
        updateBoard();
        if(checkWin()) break;
        updatePlayer();
    }
    fprintf(stdout, "%s won!!! \n", currentPlayer == PLAYER_1 ? player1 : player2);
    return 0;
}

int checkWin() {
    int winnigSum = 0;
    int player = currentPlayer == PLAYER_1 ? 'X' : 'O';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)  {
            if (board[i][j] == player) {
                winnigSum += winningBoard[i][j];
                if (winnigSum == 15) return TRUE;
            }
        }
    }
    return FALSE;
}

void begin() {
    fprintf(stdout, "enter player 1 name : ");
    scanf("%s", player1);
    fprintf(stdout, "enter player 2 name : ");
    scanf("%s", player2);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';
}

int takeInput() {
    fprintf(stdout, "%s\n", currentPlayer == PLAYER_1 ? player1 : player2);
    fprintf(stdout, "enter row [1, 2, 3] : ");
    scanf("%d", boardInput);
    if (*boardInput < 1 || *boardInput > 3)
        return FALSE;
    fprintf(stdout, "enter column [1, 2, 3] : ");
    scanf("%d", boardInput + 1);
    if (*(boardInput + 1) < 1 || *(boardInput + 1) > 3)
        return FALSE;
    if (
        board[(*boardInput) - 1][(*(boardInput + 1)) - 1] == 'X' ||
        board[(*boardInput) - 1][(*(boardInput + 1)) - 1] == 'O')
        return FALSE;
    return TRUE;
}

void draw() {
    clear();
    fprintf(stdout, "%s will play as X, %s will play as Y\n", player1, player2);
    char header[] = "\t1\t2\t3\n";
    fprintf(stdout, "%s\n", header);
    for (int i = 0; i < 3; i++) {
        fprintf(stdout, "%d\t", i + 1);
        for (int j = 0; j < 3; j++) {
            fprintf(stdout, "%c\t", board[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

void updateBoard() {
    board[(*boardInput) - 1][(*(boardInput + 1)) - 1] = currentPlayer == PLAYER_1 ? 'X' : 'O';
    draw();
}

void updatePlayer() {
    currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

void clear() {
    system("clear");
}