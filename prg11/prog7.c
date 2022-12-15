#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 256


typedef struct iris {
    double sepalLength;
    double sepalWidth;
    double petalLength;
    double petalWidth;
    char species[32];
}Iris;

void printIris(Iris iris){
    printf("sepalLength: %f, sepalWidth: %f, petalLength: %f, petalWidth: %f, species: %s\n", iris.sepalLength, iris.sepalWidth, iris.petalLength, iris.petalWidth, iris.species);
    return ;
}

Iris irisSprit(char *str){
    char *pointer;
    Iris iris;
    
    //,を用いて文字列を分割
    //https://secret-garden.hatenablog.com/entry/2015/09/02/000000
    pointer = strtok(str, ",");

    // atofを用いて、文字列をdouble型に変換
    //https://programming-place.net/ppp/contents/c/rev_res/string004.html

    iris.sepalLength = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.sepalWidth = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.petalLength = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.petalWidth = atof(pointer);
    pointer = strtok(NULL, ",");

    //改行を対策する。
    // 改行文字は最後にあることを決め打ちしている。
    //https://okwave.jp/qa/q4452927.html
    pointer[strlen(pointer)-1]='\0';
    static char tmp[64] = {'\0'};
    strcpy(iris.species, pointer);

    return iris;
}

void randomize(Iris a[], int index){
    srand((unsigned int)time(NULL));

    for(int i = index - 1; i > 0; i--){
        int j = rand() % i;

        Iris temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

double irisDistance(Iris a, Iris b){
    double distance = 0;
    distance += pow(a.sepalLength - b.sepalLength, 2);
    distance += pow(a.sepalWidth - b.sepalWidth, 2);
    distance += pow(a.petalLength - b.petalLength, 2);
    distance += pow(a.petalWidth - b.petalWidth, 2);
    distance = sqrt(distance);
    return distance;
}

int main(int argc, const char* argv[]){

    Iris lists[MAX];
    char line[MAX];  // １⾏分を読み込むための配列
    Iris iris_virginica_list[MAX];
    Iris iris_versicolor_list[MAX];
    Iris iris_setosa_list[MAX];

    FILE *fp;
    fp = fopen("iris.data", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    int i=0;
    while (fgets(line, MAX, fp) != NULL) {
        lists[i] = irisSprit(line);
        i++;
    }
    // 配列のサイズを取得
    int size = i;

    //配列をランダムにする
    randomize(lists,size);
    // for(int i = 0; i < size; i++){
    //     printIris(lists[i]);
    // }

    //2種類に分ける
    Iris array_learn[120];
    Iris array_test[30];

    for(int i = 0; i < size; i++){
        if(i < 120){
            array_learn[i] = lists[i];
        }else{
            array_test[i-120] = lists[i];
        }
    }
    // printf("array_learn\n");
    // for(int i = 0; i < 120; i++){
    //     printIris(array_learn[i]);
    // }
    // printf("array_test\n");
    // for(int i = 0; i < 30; i++){
    //     printIris(array_test[i]);
    // }

    //推定を行う
    int miss = 0;
    for(int i=0;i<30;i++){

        double smallDistance = 100;
        Iris nearDate;

        for(int j=0;j<120;j++){
            double distance = irisDistance(array_test[i],array_learn[j]);
            if(distance < smallDistance){
                smallDistance = distance;
                nearDate = array_learn[j];
            }
        }

        // printf("推定結果: %s, 正解: %s , 近侍度: %f\n",nearDate.species,array_test[i].species,smallDistance);

        if(strcmp(nearDate.species,array_test[i].species) != 0){
            miss++;
        }
    }

    printf("正解率: %0.2f %%\n",(1 - (double)miss/30)*100);

    fclose(fp);
    return 0;
}