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

unsigned int rrotate(unsigned int x, int n){
    unsigned int mask = 0;
    for(int i = 0 ; i < n ; i++){
        mask = mask | (1 << i);
    }

    unsigned int tmp = x & mask;
    tmp = tmp << (32 - n);
    x = x >> n;
    x = x | tmp;

    return x;
}

unsigned int lrotate(unsigned int x, int n){
    unsigned int mask = 0;
    for(int i = 0 ; i < n ; i++){
        mask = mask | (1 << (31 - i));
    }

    unsigned int tmp = x & mask;
    tmp = tmp >> (32 - n);
    x = x << n;
    x = x | tmp;

    return x;
}

int main(int argc, const char* argv[]){
    int num = 0;
    printf("input number: ");
    scanf("%d", &num);

    int roll = 0;
    printf("input roll: ");
    scanf("%d", &roll);

    printf("num    : ");
    printbin(num);
    printf("rrotate: ");
    printbin(rrotate(num, roll));
    printf("lrotate: ");
    printbin(lrotate(num, roll));

    return 0;
}