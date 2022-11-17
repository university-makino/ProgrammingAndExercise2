#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    int *pointer ;

    if ((pointer = (int *)malloc(4 * sizeof(int))) == NULL) {
        printf("No enough memory.¥n");
        exit(1);
    }

    pointer[0] = 100;
    pointer[1] = 200;
    pointer[2] = 300;
    pointer[3] = 400;

    printf("pointer[0] = %d\n", pointer[0]);
    printf("pointer[1] = %d\n", pointer[1]);
    printf("pointer[2] = %d\n", pointer[2]);
    printf("pointer[3] = %d\n", pointer[3]);

    free(pointer);
    return 0;
}