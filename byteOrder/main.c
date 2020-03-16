#include <stdio.h>

void testByteOrder()
{
    union {
        short s;
        char c[sizeof(short)];
    } un;
    
    un.s = 0x1234;

    printf("char size :  %ld\n", sizeof(char));
    printf("short size : %ld\n", sizeof(short));
    printf("int size : %ld\n", sizeof(int));
    printf("long size : %ld\n", sizeof(long));
    printf("float size : %ld\n", sizeof(float));
    printf("double size : %ld\n", sizeof(double));
    printf("a : 0x%x, b : 0x%x\n", un.c[0], un.c[1]);

    short t = 0x5678;
    printf("hex t: 0x%x\n", t);

    printf("c: 0x%x, d: 0x%x\n", (char)(t), (*((char*)&t + 1)) );
    
    float f = 1.0;
    printf("hex f: 0x%x\n", f);
    
    printf("@1: 0x%x, @2: 0x%x, @3: 0x%x, @4: 0x%x\n",
           (char)(f), ( *( (char*)&f + 1) ), ( *( (char*)&f + 2 ) ), ( *( (char*)&t + 3 ) ) );
}

int main(int argc, char **argv)
{
    union{
        short s;
        char c[sizeof(short)];
    }un;
    un.s = 0x0102;
    if(sizeof(short) == 2) {
        if(un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");
        else if(un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else
            printf("unknown\n");    
    } else 
        printf("sizeof(short) = %ld\n", sizeof(short));
    testByteOrder();
    return 0;
}

