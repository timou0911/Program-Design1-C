#include<stdio.h>

int main () {

    int n;
    scanf("%d", &n);

    int score[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &score[i]);
    }

    int numBA;
    scanf("%d", &numBA);

    int interval[numBA][2];
    for (int i = 0 ; i < numBA ; i++) {
        scanf("%d %d", &interval[i][0], &interval[i][1]);
    }

    for (int i = 0 ; i < numBA ; i++) {
        int below = 0;
        int between = 0;
        int upper = 0;

        for (int j = 0 ; j < n ; j++) {
            if (score[j] < interval[i][0]) {
                below++;
            }
            else if (interval[i][0] <= score[j] && score[j] < interval[i][1]) {
                between++;
            }
            else {
                upper++;
            }
        }
        printf("%d %d %d\n", below, between, upper);
    }

    return 0;
}