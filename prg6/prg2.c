#include <stdio.h>
#include <math.h>

int main(int argc, const char* argv[]){

    int r = 10;

    double area = r * r * M_PI;
    double circumference = 2 * r * M_PI;

    printf("area: %lf\n", area);
    printf("circumference: %lf\n", circumference);

    return 0;
}