#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]){

    srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

    int num = rand() % 3 + 3;
    printf("randomNumber: %d\n", num);

    return 0;
}