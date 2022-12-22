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
Elem* addElemFirst(Elem *root, int num);
void freeList(Elem *root);
void sortElem(Elem *root);
void deleteElem(Elem *root, int num);
void printHelp();
void fileWrite(Elem *root);
Elem* fileRead(Elem *root);

Elem* fileRead(Elem *root){
    Elem *p = root;
    
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
        if(p == NULL){
            p = addElemFirst(p, num);
        }else{
            addElem(p, num);
        }
    }

    fclose(fp);
    return p;

}

void fileWrite(Elem *root){
    FILE *fp;
    fp = fopen("list.txt", "w");
    Elem *p = root;
    while(p != NULL){
        fprintf(fp, "%d\n", p->num);
        p = p->next;
    }
    fclose(fp);
}


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
    Elem *p = root;
    while(p->next != NULL){
        p = p->next;
    }
    Elem *newElem = (Elem *)malloc(sizeof(Elem));
    newElem->num = num;
    newElem->next = NULL;
    p->next = newElem;

    sortElem(root);

    return root;

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

    root = fileRead(root);

    //対話型配列操作
    printf("コマンドが不明な場合は [help 0] を入力してください\n");
    while(1){
        int num = 0;
        char str[100] = {0};

        printf("コマンドを入力してください:");
        scanf("%s %d", str ,&num);
        
        if(strcmp(str, "add") == 0){
            if(root == NULL){
                root = addElemFirst(root, num);
            }else{
                addElem(root, num);
            }
        }else if(strcmp(str, "delete") == 0){
            deleteElem(root, num);
        }else if(strcmp(str, "print") == 0){
            printList(root);
        }else if(strcmp(str, "exit") == 0){
            break;
        }else if(strcmp(str, "help") == 0){
            printHelp();
        }else{
            printf("コマンドが不明です\n");
        }
    }

    fileWrite(root);
    freeList(root); 
    return 0;
}