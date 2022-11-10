#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("終了するときはquitと入力してください\n");

    while(1) {
        printf("name? ");
        scanf("%s",line);

        if(strcmp(line, "quit")==0){
            break;
        }

        fprintf(fp, "\n%s", line);
        printf("%s\n",line);
        
    }


    fclose(fp);
    return 0;
}