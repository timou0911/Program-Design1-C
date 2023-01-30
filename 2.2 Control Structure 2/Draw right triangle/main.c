#include<stdio.h>

int main () {

    int pos, level;
    scanf("%d %d", &pos, &level);

    switch(pos) {
        case 1 :
            for (int i = 0 ; i < level ; i++) {
                for (int j = 0 ; j < level - i ; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 2 :
            for (int i = 0 ; i < level ; i++) {
                for (int j = 0 ; j <= i ; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3 :
            for (int i = 0 ; i < level ; i++) {
                for (int k = 0 ; k < i ; k++) {
                    printf(" ");
                }
                for (int j = 0 ; j < level - i ; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 4 :
            for (int i = 0 ; i < level ; i++) {
                for (int j = 0 ; j < level - i - 1; j++) {
                    printf(" ");
                }
                for (int k = 0 ; k < i + 1 ; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        default :
            printf("error");
            break;
    }

    return 0;
}
}
