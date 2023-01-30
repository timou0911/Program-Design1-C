#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}

void sort_section(int *ptr, int *qtr) {
    if (ptr > qtr) {
        int *temp = ptr;
        ptr = qtr;
        qtr = temp;
    }
    for (int i = qtr-ptr-1 ; i >= 0 ; i--) {
        for (int j = 0 ; j < i+1 ; j++) {
            if (*(ptr+j) > *(ptr+j+1)) {
                int temp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = temp;
            }
        }
        for (int *k = ptr ; k <= qtr ; k++) {
            printf("%d ", *k);
        }
        printf("\n");
    }
}