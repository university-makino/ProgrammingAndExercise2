#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void) {
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("meibo.txt", "a");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    int people = 0;
    printf("名簿を追加する人数を教えてください。\n");
    printf("人数：");
    scanf("%d", &people);

    for(int i = 0; i < people; i++) {
        char str[50] = {'\0'};
        printf("\n名前を入力してください。\n");
        printf("名前：");
        scanf("%s", str);
        sprintf(str, "%s\n", str);
        fputs(str, fp);
    }


    fclose(fp);
    return 0;
}