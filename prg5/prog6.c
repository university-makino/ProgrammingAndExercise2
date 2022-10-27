#include <stdio.h>
#include <string.h>

int my_strcpy(char *dst, char *src){
    int i = 0;
    while (src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return i;
}

int main(int argc, const char* argv[]){

    char a[128] = "abc";
    char b[128];

    printf("=== old ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    //コピーされる先, コピーする文字
    my_strcpy(b,a);

    printf("=== new ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}