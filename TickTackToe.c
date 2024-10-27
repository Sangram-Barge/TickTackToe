#include <stdio.h>
#include <stdlib.h>

#define PLAYER_1 0
#define PLAYER_2 1

void clear();
void draw();
void takeInput();
void begin();

char board[3][3];
int currentPlayer = PLAYER_1;
char player1[20];
char player2[20];
int boardInput[2];

int main() {
    begin();
    for(;;) {
        draw();
        takeInput();
        board[(*boardInput) - 1][(*(boardInput + 1)) - 1] = currentPlayer == PLAYER_1 ? 'X' : 'O';
        currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }
    return 0;
}

void begin() {
    printf("enter player 1 name : ");
    scanf("%s", player1);
    printf("enter player 2 name : ");
    scanf("%s", player2);
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';
    
}

void takeInput() {
    printf("%s\n", currentPlayer == PLAYER_1 ? player1 : player2);
    printf("enter row [1, 2, 3] : ");
    scanf("%d", boardInput);
    printf("enter column [1, 2, 3] : ");
    scanf("%d", boardInput + 1);
}

void draw() {
    clear();
    printf("%s will play as X, %s will play as Y\n", player1, player2);
    char header[] = "\t1\t2\t3\n";
    printf("%s\n", header);
    for (int i = 0; i < 3; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
}

void clear() {
    system("clear");
}