#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];

    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}

void recovery(char *homework) {
    char copy[MAX_LEN + 1];
    strcpy(copy, homework);
    strcpy(homework, "");
    char * token;
    int a = 1;
    token = strtok(copy, " ");
    while(token != NULL) {
        unsigned int len = strlen(token);
        if (len >= 1 && len <= 21) {
            if (token[0] == '\n') {
                continue;
            }
            if (len == 1) {
                if (isalpha(token[0]) == 0) {
                    a = 0;
                }
            }
            else {
                if (token[len-1] == '\n') {
                    len -= 1;
                }
                for (int i = 0 ; i < len - 1 ; i++) {
                    if (isalpha(token[i]) == 0) {
                        a = 0;
                        break;
                    }
                }
                if (isalpha(token[len-1]) == 0) {
                    if ((token[len-1] != '.') && (token[len-1] != ',') && (token[len-1] != '?') && (token[len-1] != '!')) {
                        a = 0;
                    }
                }
            }
            if (a == 1) {
                strcat(homework, token);
                strcat(homework, " ");
            }
        }
        token = strtok(NULL, " ");
        a = 1;
    }
}