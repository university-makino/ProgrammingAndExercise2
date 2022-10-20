#include <stdio.h>

int main(int argc, const char* argv[]){

    int a[5] = {0};

    int *pa = a;

    printf("pa + 0 : %p\n", pa);
    printf("pa + 1 : %p\n", pa + 1);
    printf("pa + 2 : %p\n", pa + 2);
    printf("pa + 3 : %p\n", pa + 3);
    printf("pa + 4 : %p\n", pa + 4);

    printf("\n");

    printf("a[0] : %p\n", &a[0]);
    printf("a[1] : %p\n", &a[1]);
    printf("a[2] : %p\n", &a[2]);
    printf("a[3] : %p\n", &a[3]);
    printf("a[4] : %p\n", &a[4]);


    

    return 0;
}