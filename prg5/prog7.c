#include <stdio.h>
#include <string.h>

int swap_str(char *str1, char *str2){
    char tmp[128];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
    return 0;
}

int main(int argc, const char* argv[]){

    char a[128] = "abcde"; 
    char b[128] = "xyz";

    printf("=== old ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    swap_str(a,b);

    printf("=== new ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);


    return 0;
}