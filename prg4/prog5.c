#include <stdio.h>

int main(int argc, const char* argv[]){

    int a[5] = {10,20,30,40,50};

    int *pa = a;

    for(int i = 0; i < 5; i++){
        *(pa + i) = *(pa + i) + 1;
        printf("a[%d] : %d\n", i, a[i]);
    }


    return 0;
}