#include<stdio.h>

int main () {

    int disc[6] = {0};
    int d1, d2;

    for (int i = 0 ; i < 75 ; i++) {
        scanf("%d %d", &d1, &d2);

        if (d2 % 2) {
            if (disc[d1-1] == 9) {
                disc[d1-1] = 0;
            }
            else {
                disc[d1-1]++;
            }
        }
        else {
            if (disc[d1-1] == 0) {
                disc[d1-1] = 9;
            }
            else {
                disc[d1-1]--;
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++) {
        printf("%d ", disc[i]);
    }

    return 0;
}