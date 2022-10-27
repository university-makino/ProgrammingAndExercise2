#include <stdio.h>

int main(int argc, const char* argv[]){

    int i;
    char a[][5] = {"LISP","C","Ada" };  
    char *p[] = {"PAUL","X","MAC"};


    int index1 = sizeof a / sizeof a[0];
    printf("index1 = %d\n", index1);
    for (i = 0; i < index1; i++){
        printf("a[%d] = \"%s\"\n", i, a[i]);

    }

    printf("\n");

    int index2 = sizeof p / sizeof p[0];
    printf("index2 = %d\n", index2);
    for (i = 0; i < index2; i++){
        printf("p[%d] = \"%s\"\n", i, p[i]);

    }

    return 0;
}