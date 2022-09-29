#include <stdio.h>

int printbin(unsigned int x){
    for(int i = 31 ; i >= 0 ; i--){
        if(x & (1 << i)){
            printf("1");
        }else{
            printf("0");
        }
    }

    printf("\n");

    return 0;
}

int main(int argc, const char* argv[]){
    int num = 0;
    printf("input number: ");
    scanf("%d", &num);

    printbin(num);

    return 0;
}