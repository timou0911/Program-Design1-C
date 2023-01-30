#include<stdio.h>

int main () {

    int hex;
    scanf("%x", &hex);

    printf("%d.%d.%d.%d", (hex & 0xFF000000)>>24, (hex & 0x00FF0000)>>16, (hex & 0x0000FF00)>>8, hex & 0x000000FF);
    //printf("%d.%d.%d.%d", hex>>24, hex<<8>>24, hex<<16>>24, hex<<24>>24);
    return 0;
}
