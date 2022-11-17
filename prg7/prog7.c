#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {

    int* pointer = (int*)malloc(1 * sizeof(int));
    int count = 0;

    while(1){
        printf("number? ");
        scanf("%d",&pointer[count]);

        if(pointer[count] < 0){
            break;
        }

        pointer = (int*)realloc(pointer, (count + 1) * sizeof(int));

        count++;
    }

    for(int i = 0;i < count ; i++){
        printf("pointer[%d] = %d\n",i,pointer[i]);
    }

    free(pointer);
    return 0;
}