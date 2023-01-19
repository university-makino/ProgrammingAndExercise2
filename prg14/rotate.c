#include <stdio.h>

void printBin(unsigned int n){
    if(n == 0){
        return;
    }
    printBin(n >> 1);
    printf("%d", n & 1);
}

unsigned int rRotate(unsigned int x, int n){
    return (x >> n) | (x << (32 - n));
}

unsigned int lRotate(unsigned int x, int n){
    return (x << n) | (x >> (32 - n));
}

int main(int argc, const char* argv[]){

    unsigned int number = 0;
    printf("Input a number : ");
    scanf("%d", &number);

    printf("通常\n");
    printBin(number);
    printf("\n");

    printf("右に回転\n");
    printBin(rRotate(number, 1));
    printf("\n");
    printBin(rRotate(number, 2));
    printf("\n");
    printBin(rRotate(number, 3));
    printf("\n");
    printBin(rRotate(number, 4));
    printf("\n");
    printBin(rRotate(number, 5));
    printf("\n");

    

    printf("左に回転\n");
    printBin(lRotate(number, 1));
    printf("\n");
    printBin(lRotate(number, 2));
    printf("\n");
    printBin(lRotate(number, 3));
    printf("\n");
    printBin(lRotate(number, 4));
    printf("\n");
    printBin(lRotate(number, 5));
    printf("\n");

    return 0;
}