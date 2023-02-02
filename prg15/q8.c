#include <stdio.h>
#include <stdlib.h>

typedef struct trial{
    int speed;
    int distance;
}Trial;

void dispTrial(Trial *t){
    printf("speed: %d, distance: %d\n", t->speed, t->distance);
}

double estimationFunction(double a,int distance){

    //y=ax
    return a*distance;
}

int main(int argc, const char* argv[]){

    Trial trialList[100] = {0};

    //ファイル読み込み
    FILE *fp;
    fp = fopen("cars.csv", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // 入力部分
    char line[256];
    int inputIndex = 0;
    while(fgets(line, 256, fp) != NULL){
        int speed = 0;
        int distance = 0;
        sscanf(line, "%d,%d", &speed, &distance);

        Trial t = {speed, distance};

        trialList[inputIndex] = t;
        inputIndex++;
    }

    //線形回帰 (y = ax + b)
    int sumUp = 0;
    int sumDown = 0;
    for(int i = 0; i < inputIndex; i++){
        sumUp += trialList[i].speed * trialList[i].distance;
        sumDown += trialList[i].speed * trialList[i].speed;
    }
    double a = sumUp / (double)sumDown;

    printf("a: %f\n", a);

    // 推定部分

    double MSE = 0;
    for(int i = 0; i < inputIndex; i++){

        double estimatedDistance = estimationFunction(a,trialList[i].speed);

        double error = estimatedDistance - trialList[i].distance;

        printf("speed: %d, distance: %d, 推定: %f, 誤差: %f\n", trialList[i].speed, trialList[i].distance, estimatedDistance, error);

        //Mean Square Error
        MSE += error * error;
    }

    MSE = MSE / inputIndex;

    printf("MSE: %f\n", MSE);

    

    return 0;
}