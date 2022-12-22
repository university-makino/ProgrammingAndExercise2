#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct elem{
    int num;
    struct elem *next;
}Elem;

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

int main(int argc, const char* argv[]){

    Elem *root = NULL;

    Elem l1 = {10 , root};
    root = &l1;
    Elem l2 = {20 , root};
    root = &l2;
    Elem l3 = {30 , root};
    root = &l3;

    printf("先頭に挿入のみ\n");
    printList(root);

    addElem(root, 40);

    printf("末尾に挿入\n");
    printList(root);


    return 0;
}