#include<stdio.h>

int main () {

    int num = 0, min = 0, max = 0;

    scanf("%d", &num);
    min = num;
    max = num;

    while(num != -1) {
        if (num < min) {
        	min = num;
        }
        if (num > max) {
        	max = num;
        }
        scanf("%d", &num);
    }
    printf("%d", max - min);
    return 0;
}

