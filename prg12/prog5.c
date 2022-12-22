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
void sortElem(Elem *root);

void sortElem(Elem *root){
    Elem *p = root;
    while(p != NULL){
        Elem *q = p->next;
        while(q != NULL){
            if(p->num > q->num){
                int tmp = p->num;
                p->num = q->num;
                q->num = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
}


void printList(Elem *root){
    Elem *p = root;
    while(p != NULL){
        printf("%d\n", p->num);
        p = p->next;
    }
}


Elem* addElem(Elem *root, int num){

    Elem *current = root;
    Elem *prev = NULL;

    while(current != NULL){
        if(current->num > num){
            break;
        }
        prev = current;
        current = current->next;
    }

    Elem *newElem = (Elem*)malloc(sizeof(Elem));
    newElem->num = num;

    //  場合分けを行う。
    /*
    if(current == NULL && prev == NULL){
        //空っぽだった場合は先頭に追加
        newElem->next = NULL;
        return newElem;

    }else if(current == NULL && prev != NULL){
        //一個も見つからば買った場合は末尾に追加
        newElem->next = NULL;
        prev->next = newElem;
        return root;

    }else if(prev == NULL){
        //先頭に要素を挿入する場合。（ROOTの値が入れたい値より大きい場合）
        newElem->next = root;
        return newElem;

    }else{
        //prevとcurrentの間に追加
        newElem->next = current;
        prev->next = newElem;
        return root;
    }
    */

    // 場合わけをきれいにする。
    if(prev == NULL){
        //空っぽだった場合は先頭に追加
        newElem->next = NULL;
        return newElem;
    }else{
        //prevとcurrentの間に追加
        newElem->next = current;
        prev->next = newElem;
        return root;
    }
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