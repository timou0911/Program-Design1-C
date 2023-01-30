#include <stdio.h>

int main() {

    int num;
    char ch;

    scanf("%d\n", &num);
    scanf("%c", &ch);
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    printf("%c", ch);

    while (1) {
        scanf("%c", &ch);
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        else if (ch == ' ') {
            printf("%c", ch);
            scanf("%c", &ch);
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 'a' + 'A';
            }
        }
        else if (ch == ';' || ch == '.' || ch == ',') {
            scanf("%c", &ch);
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 'a' + 'A';
            }
            num -= 1;
            if (!num) {
                break;
            }
            else {
                printf("\n");
            }
        }
        printf("%c", ch);
    }
    return 0;
}