#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}

unsigned long construct(unsigned char parts[16]) {
    unsigned long long l1 = 0, l2 = 0;
    for(int i = 0 ; i < 8 ; i++) {
        l1 += ((unsigned long long)parts[7-i] << (8*(7-i)));
    }
    for(int i = 0 ; i < 8 ; i++) {
        l2 += ((unsigned long long)parts[15-i] << (8*(7-i)));
    }
    return (l1 ^ l2);
}