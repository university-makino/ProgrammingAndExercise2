#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char* argv[]){

    int peopleOfNumber = 0;
    int *points;

    int sum = 0;
    double average = 0.0;

    printf("人数を教えてください。\n");
    printf("peopleOfNumber? ");
    scanf("%d",&peopleOfNumber);

    points  = (int*)malloc(peopleOfNumber * sizeof(int));

    // 人数分の点数を入力
    for(int i = 0; i < peopleOfNumber ; i++){
        printf("%d人目の点数? ",i+1);
        scanf("%d",&points[i]);

        sum += points[i];

    }

    // 平均点を計算
    average = (double)sum / peopleOfNumber;

    // 偏差を計算
    int *deviation = (int*)malloc(peopleOfNumber * sizeof(int));
    for(int i = 0; i < peopleOfNumber ; i++){
        // printf("%d人目の偏差 = %f\n",i,points[i] - average);
        deviation[i] = points[i] - average;
    }

    // 標準偏差を計算
    double standardDeviation = 0.0;
    for(int i = 0; i < peopleOfNumber ; i++){
        standardDeviation += deviation[i] * deviation[i];
    }
    standardDeviation = sqrt(standardDeviation / peopleOfNumber);

    printf("平均点 = %f\n",average);
    printf("標準偏差 = %f\n",standardDeviation);

    // 確率
    double probability = 0.0;
    probability = (1 / (sqrt(2 * M_PI) * standardDeviation)) * exp(-((50 - average) * (50 - average)) / (2 * standardDeviation * standardDeviation)) * 100;

    printf("50点を取る確率 = %f\n",probability);




    free(points);
    free(deviation);
    return 0;
}