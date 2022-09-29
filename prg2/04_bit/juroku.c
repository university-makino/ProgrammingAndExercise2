#include <stdio.h>

char fixBit(int num);

int main(int argc, const char* argv[]){

    unsigned int num = 0;
    printf("input number: ");
    scanf("%d", &num);

    int underBit = num /16;
    int abodeBit = num % 16;

    // printf("underBit: %d\n", underBit);
    // printf("abodeBit: %d\n", abodeBit);

    // printf("underBit: %c\n", fixBit(underBit));
    // printf("abodeBit: %c\n", fixBit(abodeBit));

    printf("result: %c%c\n", fixBit(underBit), fixBit(abodeBit));


    return 0;
}

char fixBit(int num){
    if(num < 10){
        return num + '0';
    }else{
        return num - 10 + 'A';
    }
}