#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    char *pointer;

    if ((pointer = (char *)malloc(5 * sizeof(char))) == NULL) {
        printf("No enough memory.¥n");
        exit(1);
    }

    strcpy(pointer, "hoge");

    printf("pointer = %s\n", pointer);

    free(pointer);
    return 0;
}