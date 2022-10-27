#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]){

    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";

    printf("str1[128] : strlen = %lu, sizeof = %lu\n", strlen(str1), sizeof(str1));
    printf("str2[]    : strlen = %lu, sizeof = %lu\n", strlen(str2), sizeof(str2));
    printf("str       : strlen = %lu, sizeof = %lu\n", strlen(str), sizeof(str));

    return 0;
}