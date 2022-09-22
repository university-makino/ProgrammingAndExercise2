#include <stdio.h>

int main(int argc, const char* argv[]){

    int radius = 0;

    printf("Input radius: ");
    scanf("%d", &radius);

    printf("Area: %04f\n", 3.14 * radius * radius);
    printf("Circumference: %04f\n", 2 * 3.14 * radius);

    return 0;
}