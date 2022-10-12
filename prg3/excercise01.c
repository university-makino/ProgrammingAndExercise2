#include <stdio.h>
#include <math.h>

void getAvgSD(int num1, int num2, double *avg, double *sd){
    *avg = (num1 + num2) / 2.0;
    *sd = (num1 - *avg) * (num1 - *avg) + (num2 - *avg) * (num2 - *avg);
    *sd = sqrt(*sd / 2.0);
}

int main(int argc, const char* argv[]){

    int num1 = 0;
    int num2 = 0;
    double average = 0;
    double standardDeviation = 0;

    printf("num1: ");
    scanf("%d",&num1);
    printf("num2: ");
    scanf("%d",&num2);

    getAvgSD(num1, num2, &average, &standardDeviation);

    printf("average = %f  standardDeviation = %f\n",average ,standardDeviation);

    return 0;
}