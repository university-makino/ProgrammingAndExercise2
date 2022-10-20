#include <stdio.h>

void tenTimesFunc(int index ,int *pa){
    for(int i = 0; i < index; i++){
        *(pa + i) = *(pa + i) * 10;
    }
}

int main(int argc, const char* argv[]){

    int a[5] = {10,20,30,40,50};
    int b[4] = {3,4,5,6};

    int *pa = a;
    int aIndex = sizeof(a) / sizeof(int);
    int *pb = b;
    int bIndex = sizeof(b) / sizeof(int);

    tenTimesFunc(aIndex,pa);
    tenTimesFunc(bIndex,pb);

    for(int i = 0; i < 5; i++){
        printf("a[%d] : %d\n", i, a[i]);
    }

    printf("\n");

    for(int i = 0; i < 4; i++){
        printf("b[%d] : %d\n", i, b[i]);
    }


    return 0;
}