#include<stdio.h>
#include<math.h>

int main () {

    int num;
    scanf("%d\n", &num);

    char shape[num];
    for(int i = 0 ; i < num ; i++) {
    	scanf("%c", &shape[i]);
    }
    scanf("\n");
    int turn = log2(num);

    char card[turn];
    for (int i = 0 ; i < turn ; i++) {
    	scanf("%c", &card[i]);
    }

    int winner[num][2];
    int card_num = 0;

    for (int i = 0 ; i < num ; i++) {
        winner[i][0] = shape[i];
        winner[i][1] = i+1;
    }

    while (turn) {

        for (int i = 0 ; i < pow(2, turn-1) ; i++) {
            if ((winner[i*2][0] == 'p' && winner[i*2+1][0] == 'r') || (winner[i*2][0] == 'r' && winner[i*2+1][0] == 's') || (winner[i*2][0] == 's' && winner[i*2+1][0] == 'p')) {
                winner[i*2+1][0] = winner[i*2][0];
                winner[i*2+1][1] = winner[i*2][1];
            }
            else if (winner[i*2][0] == winner[i*2+1][0]) {
                if (card[card_num] == 's') {
                    winner[i*2+1][0] = winner[i*2][0];
                    winner[i*2+1][1] = winner[i*2][1];
                }
                else {
                    winner[i*2][0] = winner[i*2+1][0];
                    winner[i*2][1] = winner[i*2+1][1];
                }
            }
            else {
                winner[i*2][0] = winner[i*2+1][0];
                winner[i*2][1] = winner[i*2+1][1];
            }
        }
        turn--;
        card_num++;
        for (int i = 0 ; i < pow(2, turn) ; i++) {
            winner[i][0] = winner[i*2][0];
            winner[i][1] = winner[i*2][1];
        }
    }
    printf("%d", winner[0][1]);

    return 0;
}
