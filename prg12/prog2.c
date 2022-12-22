#include <stdio.h>


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

int main(int argc, const char* argv[]){

    Elem *root = NULL;

    Elem l1 = {10 , root};
    root = &l1;
    Elem l2 = {20 , root};
    root = &l2;
    Elem l3 = {30 , root};
    root = &l3;

    printList(root);


    return 0;
}