#include<stdio.h>
#include<string.h>
#define MOVE "PATA PATA PATA PON"
#define ATTACK "PON PON PATA PON"
#define BACKANDDEFEND "CHAKA CHAKA PATA PON"

int main () {

    int distance, blood, legals = 0;
    char input[700], commands[40][30];
    scanf("%d%d\n", &distance, &blood);
    fgets(input, 700, stdin);

    for (int i = 0 ; i < strlen(input) ; i++) {
        if (input[i] == ',') {
            input[i] = '.';
        }
    }
    char *token = strtok(input, ".");
    int k = 0;
    while (token != NULL) {
        strcpy(commands[k], token);
        k++;
       // printf("%s\n", token);
        token = strtok(NULL, ".");
    }

    //printf("%d\n", k);
    commands[k-1][strlen(commands[k-1])-1] = 0;
    for (int c = 0 ; c < k ; c++) {
        if (c == 30) {
            break;
        }
        if (strcmp(commands[c], MOVE) == 0) {
            legals++;
            distance--;
            if (distance == 0) {
                printf("NO %d", blood);
                return 0;
            }
            if ((c+1) % 10 == 0) {
                printf("NO %d", blood);
                return 0;
            }
            //printf("%s %d move %d %d\n", commands[c], legals, distance, blood);
        }
        else if (strcmp(commands[c], ATTACK) == 0) {
            legals++;
            if (distance <= 3) {
                blood--;
                if (blood == 0) {
                    printf("YES %d", legals);
                    return 0;
                }
            }
            if ((c+1) % 10 == 0) {
                printf("NO %d", blood);
                return 0;
            }
           // printf("%s %d attack %d %d\n", commands[c], legals, distance, blood);
        }
        else if (strcmp(commands[c], BACKANDDEFEND) == 0) {
            legals++;
            distance++;
            //printf("%s %d back %d %d\n", commands[c], legals, distance, blood);
        }
        else {
            //printf("%s\n", commands[c]);
            if ((c+1) % 10 == 0) {
                printf("NO %d", blood);
                return 0;
            }
        }
    }
    printf("NO %d", blood);
    return 0;
}
