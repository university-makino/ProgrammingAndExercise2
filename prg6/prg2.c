#include <stdio.h>

int main(int argc, const char* argv[]){

    int r = 10;

    double area = r * r * 3.14;
    double circumference = 2 * r * 3.14;

    printf("area: %lf\n", area);
    printf("circumference: %lf\n", circumference);

    return 0;
}