#include <stdio.h>

int main(int argc, const char* argv[]){

    int firstNum = 0;
    int secondNum = 0;

    printf("%d\n",firstNum);
    printf("%d\n",secondNum);

    int *firstNumAddress = &firstNum;
    int *secondNumAddress = &secondNum;

    *firstNumAddress = 10;
    *secondNumAddress = 20;

    printf("%d\n",firstNum);
    printf("%d\n",secondNum);

    return 0;
}