#include<stdio.h>

int parse(int [20][20], int, int);

int main () {

    int N;
    scanf("%d", &N);
    int arr[20][20] = {0};

    for (int i = 0 ; i < N ; i++) {
        int item;
        scanf("%d", &item);

        if (item == 0) {
            continue;
        }
        for (int j = 0; j < item ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int count = 0;
    for (int i = 0 ; i < N ; i++) {
        count += parse(arr, i, 0);
    }

    printf("%d", count);

    return 0;
}

int parse(int arr[20][20], int item, int count) {
    if (arr[item][0] == 0) {
        count += 1;
        return count;
    }

    for (int i = 0 ; arr[item][i] != 0 ; i++) {
        count = parse(arr, arr[item][i] - 1, count);
    }

    return count;
}