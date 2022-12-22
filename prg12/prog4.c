#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct elem{
    int num;
    struct elem *next;
}Elem;


void printList(Elem *root);
void addElem(Elem *root, int num);
Elem* addElemFirst(Elem *root, int num);
void freeList(Elem *root);


void printList(Elem *root){
    Elem *p = root;
    while(p != NULL){
        printf("%d\n", p->num);
        p = p->next;
    }
}

void addElem(Elem *root, int num){
    Elem *p = root;
    while(p->next != NULL){
        p = p->next;
    }
    Elem *newElem = (Elem *)malloc(sizeof(Elem));
    newElem->num = num;
    newElem->next = NULL;
    p->next = newElem;


}

Elem* addElemFirst(Elem *root, int num){
    Elem *newElem = (Elem *)malloc(sizeof(Elem));
    newElem->num = num;
    newElem->next = root;
    root = newElem;
    return root;
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

    // 先頭に追加
    root = addElemFirst(root, 10);

    // 末尾に追加
    addElem(root, 40);
    addElem(root, 30);
    addElem(root, 20);
    addElem(root, 50);

    // 出力
    printList(root);

    freeList(root); 
    return 0;
}