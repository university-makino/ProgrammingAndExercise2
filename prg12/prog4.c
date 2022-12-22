#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct elem{
    int num;
    struct elem *next;
}Elem;


void printList(Elem *root);
Elem* addElem(Elem *root, int num);
void freeList(Elem *root);


void printList(Elem *root){
    Elem *p = root;
    while(p != NULL){
        printf("%d\n", p->num);
        p = p->next;
    }
}

Elem* addElem(Elem *root, int num){
    // 関数の処理が終了しても消えないようにマロックしないといけない。
    Elem *newElem = (Elem *)malloc(sizeof(Elem));
    //データ部とポインタ部を初期化
    newElem->num = num;
    newElem->next = root;

    return newElem;

}

void freeList(Elem *root){
    Elem *p = root;
    while(p != NULL){
        Elem *next = p->next;
        free(p);
        p = next;
    }
}

int main(int argc, const char* argv[]){

    Elem *root = NULL;

    root = addElem(root, 10);
    root = addElem(root, 40);
    root = addElem(root, 30);
    root = addElem(root, 20);
    root = addElem(root, 50);

    // 出力
    printList(root);

    freeList(root); 
    return 0;
}