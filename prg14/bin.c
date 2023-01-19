#include <stdio.h>

// 数値計算で求める方法
void printBin(unsigned int n){
    if(n == 0){
        return;
    }
    printBin(n / 2);
    printf("%d", n % 2);
}

// ビット演算で求める方法
void printBin2(unsigned int n){
    if(n == 0){
        return;
    }
    printBin(n >> 1);
    printf("%d", n & 1);
}

int main(int argc, const char* argv[]){

    unsigned int number = 0;
    printf("Input a number : ");
    scanf("%d", &number);


    printf("数値演算で求める方法\n"); 
    printBin(number);
    printf("\n");


    printf("ビット演算で求める方法\n");
    printBin2(number);
    printf("\n");

    return 0;
}