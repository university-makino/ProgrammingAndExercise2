#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void) {
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("number.txt", "w");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    for(int i = 0; i < 100; i++) {
        char str[10] = {'\0'};
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);
    return 0;
}