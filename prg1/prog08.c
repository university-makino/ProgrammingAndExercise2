#include <stdio.h>
#define DISPLAY_NUM 100
#define FOO_NUM 2
#define BAR_NUM 3

int main(int argc, const char* argv[]){

    for(int i = 0 ; i < DISPLAY_NUM ; i++){
        printf("hoge");

        if(i % FOO_NUM == FOO_NUM - 1){
            printf("foo");
        }
        if(i % BAR_NUM == BAR_NUM - 1){
            printf("bar");
        }

        printf("\n");
    }

    return 0;
}