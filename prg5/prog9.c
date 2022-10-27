#include <stdio.h>
#include <string.h>

int swap_str_ptr(char **str1, char **str2){
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
    return 0;
}

int sort_str_ptr(char **str1, char **str2){
    if (strcmp(*str1, *str2) < 0){
        swap_str_ptr(str1, str2);
    }
    return 0;
}

int main(int argc, const char* argv[]){

    char *a = "abcde "; 
    char *b = "xyz";

    printf("=== old ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    sort_str_ptr(&a,&b);

    printf("=== new ==== \n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);


    return 0;
}