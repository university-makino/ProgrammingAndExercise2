#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void) {
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("prime.txt", "w");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    //prime
    for(int i = 0; i < 100; i++) {
        int flag = 0;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            char str[10] = {'\0'};
            sprintf(str, "%d\n", i);
            fputs(str, fp);
        }
    }

    fclose(fp);
    return 0;
}