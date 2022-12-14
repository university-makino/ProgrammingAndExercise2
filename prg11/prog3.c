#include <stdio.h>

int calc(int n){
    if(n == 1 || n == 2){
        return 1;
    }else{
        return calc(n-1) + calc(n-2);
    }
}

int main(int argc, const char* argv[]){

    printf("%d\n", calc(10) );

    return 0;
}