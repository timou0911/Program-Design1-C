#include<stdio.h>

int main () {
    int length;
    long int pre = 0, s_now;
    scanf("%d\n", &length);

    for(int i = 0 ; i < length ; i++) {
        scanf("%ld", &s_now);
        pre += s_now;
        if (pre % s_now == 0) {
            printf("%ld %ld\n", pre, s_now);
        }
    }
    return 0;
}