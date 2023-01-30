#include<stdio.h>

int main () {

    int table[8][8] = {0};
    int record[8][8] = {0};
    int card, line = 0;

    for (int i  = 0 ; i < 8 ; i++) {
    	for (int j = 0 ; j < 8 ; j++) {
        	scanf("%d", &table[i][j]);
        }
    }

    for (int k = 0 ; k < 64 ; k++) {
        scanf("%d", &card);
        for (int i = 0 ; i < 8; i++) {
            for (int j = 0 ; j < 8 ; j++) {
                if (table[i][j] == card) {
                    record[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0 ; i < 8 ; i++) {
        int count_h = 0;
        int count_v = 0;

        for (int j = 0 ; j < 8 ; j++) {
            count_h += record[i][j];
            count_v += record[j][i];
        }
        if (count_h == 8) {
            line ++;
        }
        if (count_v == 8) {
            line ++;
        }
    }

    int count_d = 0;
    int count_rd = 0;

    for (int i = 0 ; i < 8 ; i++) {
        count_d += record[i][i];
        count_rd += record[i][7-i];

        if (count_d == 8) {
            line ++;
        }
        if (count_rd == 8) {
            line ++;
        }
    }
    printf("%d", line);
    /*
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            printf("%d ", record[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}