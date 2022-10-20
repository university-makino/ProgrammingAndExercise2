#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{

    srand((unsigned)time(NULL));

    int list[20] = {0};

    for (int i = 0; i < 20; i++){
        //乱数を取得
        list[i] = rand() % 100; //取得する値を99～0の間とする

        printf("%02d ", list[i]);

        if (i % 5 == 4){
            printf("\n");
        }
    }



    return 0;
}