#include <stdio.h>
#include <stdlib.h>

typedef struct trial{
    int speed;
    int distance;
}Trial;

void dispTrial(Trial *t){
    printf("speed: %d, distance: %d\n", t->speed, t->distance);
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

    // 出力部分
    for(int i = 0; i < inputIndex; i++){
        dispTrial(&trialList[i]);
    }

    return 0;
}