#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}

void convert(char *arr[], int count) {
    char arr1[count][BUFFER_LEN*4];
    for (int i = 0 ; i < count ; i++) {
        int track = 0;
        for (int j = 0 ; j < strlen(arr[i]) ; j++) {
            if (arr[i][j] == '\n') {
                arr1[i][track] = '\n';
                break;
            }
            else if (arr[i][j] == ' ') {
                arr1[i][track++] = ' ';
            }
            else if (arr[i][j] >= 'a' && arr[i][j] <= 'o') {
                arr1[i][track++] = '(';
                arr1[i][track++] = (char)('2'+(arr[i][j]-'a')/3);
                arr1[i][track++] = ')';
                arr1[i][track++] = (char)('1'+(arr[i][j]-'a')%3);
            }
            else if (arr[i][j] >= 'p' && arr[i][j] <= 's') {
                arr1[i][track++] = '(';
                arr1[i][track++] = '7';
                arr1[i][track++] = ')';
                arr1[i][track++] = (char)('1'+(arr[i][j]-'p')%4);
            }
            else if (arr[i][j] >= 't' && arr[i][j] <= 'v') {
                arr1[i][track++] = '(';
                arr1[i][track++] = '8';
                arr1[i][track++] = ')';
                arr1[i][track++] = (char)('1'+(arr[i][j]-'t')%3);
            }
            else if (arr[i][j] >= 'w' && arr[i][j] <= 'z') {
                arr1[i][track++] = '(';
                arr1[i][track++] = '9';
                arr1[i][track++] = ')';
                arr1[i][track++] = (char)('1'+(arr[i][j]-'w')%4);
            }
        }
    }
    for (int i = 0 ; i < count ; i++) {
        strcpy(arr[i], arr1[i]);
    }
}