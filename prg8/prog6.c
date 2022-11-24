#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Iris getIrisAverage(Iris *iris_list, int size){

    Iris aveIris;

    double sepalLength_Average = 0;
    double sepalWidth_Average = 0;
    double petalLength_Average = 0;
    double petalWidth_Average = 0;

    for(int j=0;j<size;j++){
        sepalLength_Average += iris_list[j].sepalLength;
        sepalWidth_Average += iris_list[j].sepalWidth;
        petalLength_Average += iris_list[j].petalLength;
        petalWidth_Average += iris_list[j].petalWidth;
        // printIris(iris_list[j]);
    }

    sepalLength_Average = sepalLength_Average/size;
    sepalWidth_Average = sepalWidth_Average/size;
    petalLength_Average = petalLength_Average/size;
    petalWidth_Average = petalWidth_Average/size;

    // printf("virginica: sepalLength: %f, sepalWidth: %f, petalLength: %f, petalWidth: %f\n", sepalLength_Average, sepalWidth_Average, petalLength_Average, petalWidth_Average);

    aveIris.sepalLength = sepalLength_Average;
    aveIris.sepalWidth = sepalWidth_Average;
    aveIris.petalLength = petalLength_Average;
    aveIris.petalWidth = petalWidth_Average;

    return aveIris;
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

    // リストを仕分ける。
    int iris_virginica_count = 0;
    int iris_versicolor_count = 0;
    int iris_setosa_count = 0;

    for(int j=0;j<i;j++){
        if(strcmp(lists[j].species,"Iris-virginica")==0){
            iris_virginica_list[iris_virginica_count] = lists[j];
            iris_virginica_count++;

        }else if(strcmp(lists[j].species,"Iris-versicolor")==0){
            iris_versicolor_list[iris_versicolor_count] = lists[j];
            iris_versicolor_count++;

        }else if(strcmp(lists[j].species,"Iris-setosa")==0){
            iris_setosa_list[iris_setosa_count] = lists[j];
            iris_setosa_count++;

        }
    }

    // リストで平均を出す。
    printf("＝＝＝平均＝＝＝\n");
    Iris aveVirginica = getIrisAverage(iris_virginica_list, iris_virginica_count);
    Iris aveVersicolor = getIrisAverage(iris_versicolor_list, iris_versicolor_count);
    Iris aveSetosa = getIrisAverage(iris_setosa_list, iris_setosa_count);

    printf("Versicolor\n");
    printIris(aveVersicolor);
    printf("Virginica\n");
    printIris(aveVirginica);
    printf("Setosa\n");
    printIris(aveSetosa);


    fclose(fp);

    return 0;
}