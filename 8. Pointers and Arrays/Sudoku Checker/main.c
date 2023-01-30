#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM]) {
    int a = 0;
    int ans[9][9] = {0};
    for (int *p = grid_p[0] ; p < grid_p[8]+9 ; p++) {
        for (int i = 0 ; i < 9 ; i++) {
            if ((p != grid_p[a/9]+i) && (*p == *(grid_p[a/9]+i))) {
                ans[a/9][a%9] = 1;
            }
            if ((p != grid_p[i]+(a%9)) && (*p == *(grid_p[i]+(a%9)))) {
                ans[a/9][a%9] = 1;
            }
        }
        int startY = (a % 9) / 3 * 3; //3
        int startX = (a / 9) / 3 * 3; //0
        int *startP = grid_p[startX] + startY;
        int *q = startP;
        for (int i = 1; i < 10 ; i++) {
            if (i == 4 || i == 7) {
                q += 7;
            }
            else if (i == 1) {
                q = startP;
            }
            else {
                q++;
            }
            if ((q != p) && (*q == *p)) {
                int j = i - 1;
                ans[startX+(j/3)][startY+(j%3)] = 1;
            }
        }
        a++;
    }
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ;j++) {
            if (ans[i][j] == 1) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}