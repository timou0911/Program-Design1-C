#include<stdio.h>
#include<stdlib.h>
int array[1500];
int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}

int maxChandy(int size) {

    if (size == 1) {
        return array[0];
    }

    int start = array[0], from_second = 0, temp;
    int index = 1;
    while (index < size) {
        if (start > from_second) {
            temp = start;
        }
        else {
            temp = from_second;
        }
        start = from_second + array[index];
        from_second = temp;
        index++;
    }
    if (start > from_second) {
        return start;
    }
    else {
        return from_second;
    }
}