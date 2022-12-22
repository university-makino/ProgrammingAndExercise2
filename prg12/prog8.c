#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100


typedef struct elem{
    int num;
    struct elem *next;
}Elem;


void printList(Elem *root);
Elem* addElem(Elem *root, int num);
void freeList(Elem *root);
void sortElem(Elem *root);
void deleteElem(Elem *root, int num);
void printHelp();

void printHelp(){
    printf("コマンド表\n\n");
    printf("add 数値: 数値をリストに追加する\n");
    printf("delete 数値: 数値をリストから削除する\n");
    printf("print 0: リストの内容を表示する\n");
    printf("exit 0: プログラムを終了する\n");
    printf("help 0: コマンド表を表示する\n");
    printf("\n");
}

void deleteElem(Elem *root, int num){
    Elem *p = root;
    Elem *prev = NULL;
    while(p != NULL){
        if(p->num == num){
            if(prev == NULL){
                root = p->next;
            }else{
                prev->next = p->next;
            }
            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }
}

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

    //ファイル読み込み
    FILE *fp;
    fp = fopen("numlist.txt", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    //ファイルの行を読み込む
    char line[MAX];
    while (fgets(line, MAX, fp) != NULL) {
        int num = atoi(line);
        root = addElem(root, num);
    }

    printList(root);

    fclose(fp);
    freeList(root); 
    return 0;
}