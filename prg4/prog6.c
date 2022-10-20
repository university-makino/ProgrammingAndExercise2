#include <stdio.h>

void tenTimesFunc(int *pa){
    for(int i = 0; i < 5; i++){
        *(pa + i) = *(pa + i) * 10;
    }
}

int main(int argc, const char* argv[]){

    int a[5] = {10,20,30,40,50};

    int *pa = a;

    tenTimesFunc(pa);

    for(int i = 0; i < 5; i++){
        printf("a[%d] : %d\n", i, a[i]);
    }


    return 0;
}