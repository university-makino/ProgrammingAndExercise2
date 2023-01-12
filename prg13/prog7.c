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

    root = addMelem(root, "piyo", 1, 8);


    printList(root);

    root = freeMelem(root);
    return 0;
}