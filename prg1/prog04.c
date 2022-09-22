#include <stdio.h>

int main(int argc, const char* argv[]){


    for(int i = 0 ; i < 10 ; i++){
        printf("hoge");

        if(i % 3 == 2){
            printf("\n");
        }
    }

    return 0;
}