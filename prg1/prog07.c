#include <stdio.h>
#define NUM 10
#define NEW_LINE_NUM 3

int main(int argc, const char* argv[]){


    for(int i = 0 ; i < NUM ; i++){
        printf("hoge");

        if(i % NEW_LINE_NUM == NEW_LINE_NUM - 1){
            printf("\n");
        }
    }

    return 0;
}