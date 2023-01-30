#include<stdio.h>
#include<math.h>

int sign (int num, int arr[]);
int exponent (int num, int arr[]);
void fraction (double frac, int ex, int arr[]);
void sum_up (int a, int b, int const arrA[], int const arrB[], int ans[]);
long int to_decimal(int const ans[]);

int main(void) {

    int a, b, arrA[32] = {0}, arrB[32] = {0};
    scanf("%d %d", &a, &b);

    int a_abs = sign(a, arrA);
    int b_abs = sign(b, arrB);

    int a_ex = exponent (a_abs, arrA);
    int b_ex = exponent (b_abs, arrB);

    double a_frac = (double)(a_abs - pow(2, a_ex)) / pow(2, a_ex);
    double b_frac = (double)(b_abs - pow(2, b_ex)) / pow(2, b_ex);

    fraction (a_frac, a_ex, arrA);
    fraction (b_frac, b_ex, arrB);

    int answer[32] = {0};
    sum_up(a, b, arrA, arrB, answer);

    long int ans = to_decimal(answer);

    printf("   ");
    for (int i = 0 ; i < 32 ; i++) {
        printf("%d", arrA[i]);
        if (i == 7 || i == 15 || i == 23) {
            printf(" ");
        }
    }
    printf("\n+) ");
    for (int i = 0 ; i < 32 ; i++) {
        printf("%d", arrB[i]);
        if (i == 7 || i == 15 || i == 23) {
            printf(" ");
        }
    }
    printf("\n---------------------------------------");
    printf("\n   ");
    for (int i = 0 ; i < 32 ; i++) {
        printf("%d", answer[i]);
        if (i == 7 || i == 15 || i == 23) {
            printf(" ");
        }
    }
    printf("\n%d + %d = %ld", a, b, ans);

    return 0;
}

int sign (int num, int arr[]) {
    if (num >= 0) {
        arr[0] = 0;
        return num;
    }
    else {
        arr[0] = 1;
        return -num;
    }
}

int exponent (int num, int arr[]) {
    int p = 1, q = 0;

    while (1) {
        p *= 2;
        q ++;
        if (p > num) {
            q --;
            break;
        }
        if (q == num) {
            break;
        }
    }
    int r = q + 127;
    for (int i = 8 ; i > 0 ; i--) {
        arr[i] = r % 2;
        r /= 2;
    }
    return q;
}

void fraction (double frac, int ex, int arr[]) {
    for (int i = 9 ; i < 32 ; i++) {
        frac *= 2;
        if (frac > 1) {
            arr[i] = 1;
            frac -= 1;
        }
        else if (frac < 1) {
            arr[i] = 0;
        }
        else {
            arr[i] = 1;
            break;
        }
    }
}

void sum_up (int a, int b, int const arrA[], int const arrB[], int ans[]) {
    if (arrA[31] + arrB[31] == 0) {
        ans[31] = 0;
    }
    else if (arrA[31] + arrB[31] == 2) {
        ans[31] = 0;
        ans[30] = 1;
    }
    else {
        ans[31] = 1;
    }
    for (int i = 30 ; i >= 1 ; i--) {
        if (arrA[i] + arrB[i] + ans[i] == 0) {
            ans[i] = 0;
        }
        else if (arrA[i] + arrB[i] + ans[i] == 1) {
            ans[i] = 1;
        }
        else if (arrA[i] + arrB[i] + ans[i] == 2) {
            ans[i] = 0;
            ans[i-1] = 1;
        }
        else if (arrA[i] + arrB[i] + ans[i] == 3) {
            ans[i] = 1;
            ans[i-1] = 1;
        }
        else {

        }
    }
    if ((arrA[0] + arrB[0] + ans[0]) % 2 == 0) {
        ans[0] = 0;
    }
}

long int to_decimal(int const ans[]) {
    long int sum = 0;
    if (ans[0] == 0) {
        for (int i = 1 ; i < 32 ; i++) {
            sum += pow(2, (31-i)) * ans[i];
        }
        return sum;
    }
    else {
        for (int i = 1 ; i < 32 ; i++) {
            if (ans[i] == 0) {
                sum += pow(2, (31-i)) * 1;
            }
            else {
                sum += pow(2, (31-i)) * 0;
            }
        }
        return -(sum+1);
    }
}
