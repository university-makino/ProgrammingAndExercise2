#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){

    for(int i = 0 ; i <= 360 ; i += 10){

        double degree = i * (M_PI / 180);

        printf("%d , %f\n",i,sin(degree));
    }

    return 0;
}