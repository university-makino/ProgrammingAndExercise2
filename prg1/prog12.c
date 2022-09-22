#include <stdio.h>

int main(int argc, const char* argv[]){

    double height = 0;
    double weight = 0;

    printf("身長を入力してください(cm):");
    scanf("%lf", &height);
    printf("体重を入力してください(kg):");
    scanf("%lf", &weight);

    height /= 100;

    double bmi = weight / (height * height);

    // printf("BMIは%fです。\n", bmi);

    if(bmi < 18.5){
        printf("やせ\n");
    }else if(bmi < 25){
        printf("標準\n");
    }else if(bmi < 30){
        printf("肥満\n");
    }else{
        printf("高度肥満\n");
    }

    return 0;
}