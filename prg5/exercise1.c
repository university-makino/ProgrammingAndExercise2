#include <stdio.h>
#include <string.h>

int swap_str_ptr(char **str1, char **str2){
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
    return 0;
}

int sort_str_ptr(char **str1, char **str2){

    int str1_len = strlen(*str1);
    int str2_len = strlen(*str2);

    if (str1_len > str2_len){
        swap_str_ptr(str1, str2);
    }
    return 0;
}

int bubble_sort_str_ptr(char **str, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            sort_str_ptr(&str[j], &str[j+1]);
        }
    }
    return 0;
}

int main(int argc, const char* argv[]){

    char *list[] = {"hoge","abc","xy","fugagaga"};

    printf("=== old ==== \n");
    for(int i = 0; i < 4; i++){
        printf("list[%d] = %s\n", i, list[i]);
    }

    bubble_sort_str_ptr(list, 4);

    printf("=== new ==== \n");
    for(int i = 0; i < 4; i++){
        printf("list[%d] = %s\n", i, list[i]);
    }


    return 0;
}