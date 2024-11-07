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

char board[3][3];
int currentPlayer = PLAYER_1;
char player1[20];
char player2[20];
int boardInput[2];

int main() {
    begin();
    for(;;) {
        draw();
        while (!takeInput())
            fprintf(stderr, "invalid input please enter again\n");
        updateBoard();
    }
    return 0;
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
    currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

void clear() {
    system("clear");
}