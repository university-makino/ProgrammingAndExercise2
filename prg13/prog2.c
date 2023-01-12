#include <stdio.h>

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

int main(int argc, const char* argv[]){

    Melem *root = NULL;

    // 今まで先頭だったものをポインタ部に接続する。
    Melem e = {"hoge", 170, 60, root};
    root = &e;

    Melem e2 = {"fuga", 180, 70, root};
    root = &e2;

    Melem e3 = {"piyo", 190, 80, root};
    root = &e3;

    printList(root);

    return 0;
}