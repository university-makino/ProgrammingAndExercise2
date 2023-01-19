#include <stdio.h>

char convert16ToInt(int n){
    if(n < 10){
        return n + '0';
    }else{
        return n - 10 + 'A';
    }
}

int main(int argc, const char* argv[]){

    int number = 0;
    printf("Input a number (1~255): ");
    scanf("%d", &number);

    char c1 = convert16ToInt(number / 16);
    char c2 = convert16ToInt(number % 16);

    printf("The number %d is %c%c in hexadecimal.\n", number, c1, c2);


    return 0;
}


