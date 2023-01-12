#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct melem{
    char name[256];
    int height;
    int weight;
    struct melem *next;
}Melem;

void printHelp(){
    printf("コマンド表\n\n");
    printf("add 名前,身長,体重 : その人の身長と体重をリストに追加する\n");
    printf("delete 名前       : その人をリストから削除する\n");
    printf("print            : リストの内容を表示する\n");
    printf("exit             : プログラムを終了する\n");
    printf("help             : コマンド表を表示する\n");
    printf("\n");
}

void printList(Melem *root){
    Melem *p = root;
    while(p != NULL){
        printf("%s %d %d\n", p->name, p->height, p->weight);
        p = p->next;
    }
}

Melem* addMelem(Melem *root, char *name, int height, int weight){

    Melem *next = root;
    Melem *prev = NULL;

    // ここでprevとnextを決める。
    while(next != NULL){
        if(strcmp(next->name, name) > 0){
            break;
        }else if(strcmp(next->name, name) == 0){
            // すでにある場合は、値を更新する。
            next->height = height;
            next->weight = weight;
            return root;
        }
        prev = next;
        next = next->next;
    }

    //メモリの確保
    Melem *new = (Melem*)malloc(sizeof(Melem));

    //文字列のコピー
    strcpy(new->name, name);
    //変数の定義
    new->height = height;
    new->weight = weight;


    // 場合わけをきれいにする。
    if(prev == NULL){
        //空っぽだった場合は先頭に追加
        new->next = next;
        return new;
    }else{
        //prevとcurrentの間に追加
        new->next = next;
        prev->next = new;
        return root;
    }
}


Melem* freeMelem(Melem *root){
    Melem *p = root;
    while(p != NULL){
        Melem *next = p->next;
        // printf("%sを削除します", p->name);
        free(p);
        p = next;
        
    }
    return NULL;
}

Melem* deleteMelem(Melem *root, char *name){
    Melem *next = root;
    Melem *prev = NULL;

    while(next != NULL){
        if(strcmp(next->name, name) == 0){
            break;
        }
        prev = next;
        next = next->next;
    }

    //消すものがない場合
    if(next == NULL){
        return root;
    }

    //場合わけ
    if(prev == NULL){
        //最初のものだった場合、rootを更新する。
        root = next->next;
    }else{
        //次のものをprevのnextに接続する。
        prev->next = next->next;
    }

    free(next);
    return root;
}

int main(int argc, const char* argv[]){

    Melem *root = NULL;

    //ファイル読み込み
    FILE *fp;
    fp = fopen("meibo.csv", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    char line[256];
    while(fgets(line, 256, fp) != NULL){
        char name[256];
        int height;
        int weight;
        sscanf(line, "%[^,],%d,%d", name, &height, &weight);
        root = addMelem(root, name, height, weight);
    }

    printList(root);

    fclose(fp);
    root = freeMelem(root);
    return 0;
}