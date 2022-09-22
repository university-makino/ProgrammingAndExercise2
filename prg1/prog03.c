#include <stdio.h>

int main(int argc, const char* argv[]){

    int input = 0;
    
    printf("Enter a number: ");
    scanf("%d", &input);

    for(int i = 0 ; i < input ; i++){
        printf("Hello World!\n");
    }

    return 0;
}