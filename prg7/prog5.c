#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){

    int *pointer ;
    int inputCount = 0;

    printf("配列の要素数を入力してください。\n");
    printf("要素数：");
    scanf("%d", &inputCount);

    if ((pointer = (int *)malloc(inputCount * sizeof(int))) == NULL) {
        printf("No enough memory.¥n");
        exit(1);
    }

    for(int i = 0;i < inputCount;i++){
        printf("%d番目:",i);
        scanf("%d",&pointer[i]);
    }

    for(int i = inputCount-1;i >= 0 ; i--){
        printf("pointer[%d] = %d\n",i,pointer[i]);
    }

    free(pointer);
    return 0;
}