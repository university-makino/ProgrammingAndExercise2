#include <stdio.h>

int main(int argc, const char* argv[]){

    double list[3] = {0, 0, 0};

    printf("%p\n", &list[0]);
    printf("%p\n", &list[1]);
    printf("%p\n", &list[2]);


    return 0;
}