#include <stdio.h>
#include<stdlib.h>

int main () {

    int d1, d2, d3, d4, d5, d6, p_pt = 100, d_pt = 100;

    while(p_pt > 0 && d_pt > 0) {
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if ((d1 + d2 + d3) % 2 != 0) {
            if (d6 > d5 && d5 > d4) {
                d_pt -= 25;
            }
            else if (d4 % 2 == d5 % 2 || d5 % 2 == d6 % 2) {
                d_pt -= 5;
            }
            else {
                d_pt -= 0;
            }

            if (d_pt <= 0) {
                printf("Player wins");
            }
        }

        else {
            if (abs(d4 - d5) > d6) {
                p_pt -= 15;
            }
            else if (d4 + d5 != d6) {
                p_pt -= 5;
            }
            else {
                p_pt -= 0;
            }

            if (p_pt <= 0) {
                printf("Dragon wins");
            }
        }

    }
    /*
    if (d_pt <= 0) {
    	printf("Player wins");
    }
    else {

    }
    */
    return 0;
}