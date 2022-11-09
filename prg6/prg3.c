#include <stdio.h>
#include <math.h>

int main(int argc, const char* argv[]){

    int x1=100; 
    int y1=10; 
    int x2=200; 
    int y2=50;

    double Euclid = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    printf("Euclid: %lf\n", Euclid);

    return 0;
}