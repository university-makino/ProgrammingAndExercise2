#include <stdio.h>

char showHex(int n){
    if(n < 10){
        return n + '0';
    }else{
        return n - 10 + 'A';
    }
}

int main(int argc, const char* argv[]){

    int number = 0;
    printf("Input a number : ");
    scanf("%d", &number);

    char hex[10] = "\0";

    int r = 0;
    int q = number;

    int i = 0;
    do{
        r = q % 16;
        q = q / 16;
        hex[i] = showHex(r);
        i++;
    }while(q != 0);

    for(int j = i-1; j != -1; j--){
        putchar(hex[j]);
    }

    printf("\n");



    return 0;
}


