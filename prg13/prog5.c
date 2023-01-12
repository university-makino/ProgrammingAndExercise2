#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct melem{
    char name[256];
    int height;
    int weight;
    struct melem *next;
}Melem;

void printList(Melem *root){
    Melem *p = root;
    while(p != NULL){
        printf("%s %d %d\n", p->name, p->height, p->weight);
        p = p->next;
    }
}

Melem* addMelem(Melem *root, char *name, int height, int weight){
    //メモリの確保
    Melem *new = (Melem*)malloc(sizeof(Melem));

    //文字列のコピー
    strcpy(new->name, name);
    //変数の定義
    new->height = height;
    new->weight = weight;
    new->next = root;
    
    //次の最初になるものを返す
    return new;
}


Melem* freeMelem(Melem *root){
    Melem *p = root;
    while(p != NULL){
        Melem *next = p->next;
        free(p);
        p = next;
    }
    return NULL;
}

int main(int argc, const char* argv[]){

    Melem *root = NULL;

    // 今まで先頭だったものをポインタ部に接続する。
    root = addMelem(root, "hoge", 170, 60);
    root = addMelem(root, "fuga", 180, 70);
    root = addMelem(root, "piyo", 190, 80);

    printList(root);

    root = freeMelem(root);
    return 0;
}