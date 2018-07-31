#include <iostream>

using namespace std;

typedef struct {
    int board[3][3]; //-1: empty 0: 0 X: X  n: 1~9
    int turn;
} state;

void init(state* s) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            s->board[j][i] = -1;
    s->turn = 0;
}

void display(const state* s) {
    int i, j;
    for ( i = 0; i < 3; i++) {
        for( j = 0; j < 3; j++) {
            switch (s->board[i][j]) {
                case -1: printf(" %d ", i * 3 + j + 1); break;
                case 0: printf(" O "); break;
                case 1: printf(" X "); break;
            }
            if (j < 2)
                printf("|");
            else
                printf("\n");
        }
        if (i < 2)
            printf("---+---+---\n");
    }
}

bool move(state* s, int c) {
    int i = c / 3;
    int j = c % 3 ;
    if (s->board[i][j] != -1) {
        printf("-------------Can not be choosed!-------------\n");
        return false;
    }
    s->board[i][j] = s->turn % 2 == 0 ? 0 : 1;
    s->turn++;
    printf("-------------The Newest Board-------------\n");
    display(s);
    return true;
}
bool checkOver(state* s) {
    if (s->turn == 9) {
        printf("-------------Game Over-------------\n-------------End In A Draw-------------\n");
        return false;
    }
    if (s->turn > 4) {
        for (int i = 0; i < 3; i++) {
            if ((s->board[i][0] != -1 && s->board[i][0] == s->board[i][1] && s->board[i][1] == s->board[i][2]) || (s->board[0][i] != -1 && s->board[0][i] == s->board[1][i] && s->board[2][i] == s->board[1][i])) {
                printf("-------------Game Over-------------\n-------------Player %s Won!-------------\n", s->turn % 2 == 0 ? "X" : "O");
                return false;
            }
        }
    }
    return true;
}
bool hci(state* s) {
    printf("Hi, Player %s, Enter your move（1～9）, please.\n", s->turn % 2 == 0 ? "O" : "X");
    char c;
    do {
        c = getchar();
        while (getchar() != '\n');
        printf("\n");
    } while (c < '1' || c > '9' || !move(s, (c - '1')));
    return checkOver(s);
}

int main() {
    state s;
    init(&s);
    display(&s);
    while (hci(&s));
}
