#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void) {
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("meibo.txt", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    while (fgets(line, MAX, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}