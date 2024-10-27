#include <stdio.h>
#include <stdlib.h>

#define PLAYER_1 0
#define PLAYER_2 1

void clear();
void draw();
int* takeInput();
void begin();

int board[3][3];
int currentPlayer = PLAYER_1;
char player1[20];
char player2[20];

int main() {
    begin();
    for(;;) {
        draw();
        takeInput();

    }
    return 0;
}

void begin() {
    printf("enter player 1 name : ");
    scanf("%s", player1);
    printf("enter player 2 name : ");
    scanf("%s", player2);
}

int* takeInput() {
    printf("%s\n", currentPlayer == PLAYER_1 ? player1 : player2);
    int position[2];
    printf("enter row : ");
    scanf("%d", position);
    printf("enter column : ");
    scanf("%d", position + 1);
}

void draw() {
    clear();
    printf("%s will play as X, %s will play as Y\n", player1, player2);
    printf(" |\t1\t2\t3\n");
    printf("-------------");
    for (int i = 0; i < 3; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void clear() {
    system("clear");
}