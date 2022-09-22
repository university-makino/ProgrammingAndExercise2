#include <stdio.h>
#define NUM 10

int main(int argc, const char* argv[]){


    for(int i = 0 ; i < NUM ; i++){
        printf("hoge");

        if(i % 3 == 2){
            printf("\n");
        }
    }

    return 0;
}