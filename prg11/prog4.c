#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize(int a[], int index){
    srand((unsigned int)time(NULL));

    for(int i = index - 1; i > 0; i--){
        int j = rand() % i;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main(int argc, const char* argv[]){
    srand((unsigned int)time(NULL));

    int index = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < index; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    randomize(a, index);

    for(int i = 0; i < index; i++){
        printf("%d ", a[i]);
    }
    printf("\n");



    return 0;
}