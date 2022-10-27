#include <stdio.h>

int my_strlen(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int main(int argc, const char* argv[]){

    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";

    printf("str1[128] : strlen = %d, sizeof = %lu\n", my_strlen(str1), sizeof(str1));
    printf("str2[]    : strlen = %d, sizeof = %lu\n", my_strlen(str2), sizeof(str2));
    printf("str       : strlen = %d, sizeof = %lu\n", my_strlen(str), sizeof(str));


    return 0;
}