#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 256
#define DIVISION 5

typedef struct estimateIris{
    double estimateSetosa;
    double estimateVersicolor;
    double estimateVirginica;
}EstimateIris;

typedef struct currentIris{
    EstimateIris currentSetosa;
    EstimateIris currentVersicolor;
    EstimateIris currentVirginica;

}CurrentIris;




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

    //n種類に分ける
    Iris irisList[DIVISION][size/DIVISION];

    int n = size / DIVISION;
    for (int i = 0; i < DIVISION; i++){
        for (int j = 0; j < n; j++){
            irisList[i][j] = lists[i*n + j];
        }
    }

    for(int i = 0; i < DIVISION; i++){
        printf("irisList[%d]\n", i);
        for(int j = 0; j < n; j++){
            printIris(irisList[i][j]);
        }
    }

    fclose(fp);
    return 0;
}