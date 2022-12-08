#include <stdio.h>
#define DEBUG

int main(void) {

    #ifdef DEBUG
        printf("debug message\n");  
    #endif 

    return 0;
}