//
//  main.c
//  exercise01
//
//  Created by k22132 on 2023/01/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct elem{
    int num; // データ部
    struct elem *next; //ポインタ部
}Elem;

void print_list(Elem *root){
    Elem *current=root;
    while(current!=NULL){
        printf("%d\n",current->num);
        current=current->next;
    }
}
void print_list_recurrent(Elem *elem){
    if(elem==NULL)return;
    printf("%d\n",elem->num);
    print_list_recurrent(elem->next);
}
Elem* add_elem(Elem *root, int num){
    Elem *prev=NULL;
    Elem *current=root;
    while(current!=NULL){
        if(current->num>num)break;
        prev=current;
        current=current->next;
    }
    Elem *p=(Elem *)malloc(sizeof(Elem));
    p->num=num;
    if(prev==NULL){//空っぽだった場合
        p->next=root;// after adress elem *root
        return p;
    }
    else{//普通の挿入
        p->next=current;
        prev->next=p;
        return root;//return head adress
    }
}
Elem* delete_elem(Elem *root, int delnum){
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
Elem* free_list(Elem *root){
    Elem *current=root;
    while(current!=NULL){
        Elem *next=current->next;
        free(current);
        current=next;
    }
    return NULL;
}
void printFileList(Elem *root){
    Elem *current=root;
    FILE *fwp;
    fwp=fopen("numlist.txt","w");
    while(current!=NULL){
        fprintf(fwp,"%d\n",current->num);
        current=current->next;
    }
    fclose(fwp);
}
int main(void){
    FILE *fp;
    char line[256];
    fp=fopen("numlist.txt", "r");
    if(fp==NULL){
        printf("cannot open file");
        exit(1);
    }
    Elem *root=NULL;
    while(fgets(line,256,fp)!=NULL){
        int number=0;
        number=atoi(line);
        root=add_elem(root, number);
    }
    print_list(root);
    printf("-------\n");
        while(1){
            char input[10];
            int number = 0 ;
            printf("入力 ");
            scanf("%[^\n]",input);//%[^\n]は改行が入るまで全てのデータを取得
            char *token = strtok(input," ");
            char *command = token;
            token = strtok(NULL," ");
            char *splitNumber = token;
            if(splitNumber!=NULL){//p or q の場合行わない
                number=atoi(splitNumber);
            }
            if(*command=='a'){
                root=add_elem(root, number);
            }
            else if(*command=='d'){
                root=delete_elem(root, number);
            }
            else if(*command=='p'){
                print_list_recurrent(root);
            }
            else if(*command=='q'){
                break;
            }
            getchar();
        }
    printf("終了\n");
    printf("-------\n");
    printFileList(root);
    root=free_list(root);
    fclose(fp);
}
