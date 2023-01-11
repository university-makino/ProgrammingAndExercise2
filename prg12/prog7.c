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
Elem* deleteElem(Elem *root, int num);
void printHelp();

void printHelp(){
    printf("コマンド表\n\n");
    printf("add 数値: 数値をリストに追加する\n");
    printf("delete 数値: 数値をリストから削除する\n");
    printf("print: リストの内容を表示する\n");
    printf("exit: プログラムを終了する\n");
    printf("help: コマンド表を表示する\n");
    printf("\n");
}

Elem* deleteElem(Elem *root, int delnum){
    Elem *prev=NULL;
    Elem *current=root;
    while(current!=NULL){
        if(current->num==delnum)break;
        prev=current;
        current=current->next;
    }
    if(prev==NULL){//先頭の要素を消そうとするとき
        root=current->next;
    }else{
        prev->next=current->next;
    }
    free(current);
    return root;
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
        newElem->next = current;
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

    printf("コマンドが不明な場合は [help] を入力してください\n");

    while(1){
        char input[10];
        int number = 0 ;

        printf("入力 ");
        //%[^\n]は改行が入るまで全てのデータを取得
        scanf("%[^\n]",input);
        
        char *token = strtok(input," ");
        char *command = token;
        token = strtok(NULL," ");
        char *splitNumber = token;

        if(splitNumber!=NULL){
            number=atoi(splitNumber);
        }
        
        if(strcmp(command, "add") == 0){
            root = addElem(root, number);
        }else if(strcmp(command, "delete") == 0){
            root = deleteElem(root, number);
        }else if(strcmp(command, "print") == 0){
            printList(root);
        }else if(strcmp(command, "exit") == 0){
            break;
        }else if(strcmp(command, "help") == 0){
            printHelp();
        }else{
            printf("コマンドが不明です\n");
        }

        getchar();
    }

    freeList(root); 
    return 0;
}