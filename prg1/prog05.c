#include <stdio.h>

int main(int argc, const char* argv[]){

    for(int i = 0 ; i < 100 ; i++){
        printf("hoge");

        if(i % 2 == 1){
            printf("foo");
        }
        if(i % 3 == 2){
            printf("bar");
        }

        printf("\n");
    }

    return 0;
}