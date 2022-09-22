#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]){

    srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

    int max = 0;
    int min = 0;

    printf("min: ");
    scanf("%d", &min);
    printf("max: ");
    scanf("%d", &max);
    

    int num = rand() % (max - min + 1) + min;

    printf("num = %d\n", num);

    return 0;
}