#include<stdio.h>

int main () {
    int num, group;
    scanf("%d %d", &num, &group);
    printf("%d %d", num/group, num%group);
    return 0;
}