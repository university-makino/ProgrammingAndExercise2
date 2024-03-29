#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

Iris getIrisStandardDeviation(Iris *iris_list, int size){
    //　標準偏差を求める。
    // https://ai-trend.jp/basic-study/basic/standard-deviation/
    
        Iris aveIris = getIrisAverage(iris_list, size);
    
        Iris stdIris;

        for (int i = 0; i<size ; i++){
            stdIris.sepalLength += pow(iris_list[i].sepalLength - aveIris.sepalLength, 2);
            stdIris.sepalWidth += pow(iris_list[i].sepalWidth - aveIris.sepalWidth, 2);
            stdIris.petalLength += pow(iris_list[i].petalLength - aveIris.petalLength, 2);
            stdIris.petalWidth += pow(iris_list[i].petalWidth - aveIris.petalWidth, 2);
        }

        stdIris.sepalLength = sqrt(stdIris.sepalLength/size);
        stdIris.sepalWidth = sqrt(stdIris.sepalWidth/size);
        stdIris.petalLength = sqrt(stdIris.petalLength/size);
        stdIris.petalWidth = sqrt(stdIris.petalWidth/size);

        return stdIris;
}

void printIrisJudgementByAve(Iris *irisAveVersicolor,Iris *irisAveVirginica ,Iris *irisAveSetosa , Iris checkIris){
    //　平均値を用いて、どの種類に属するかを判定する。
    // https://www.kaggle.com/uciml/iris/discussion/111835

    double distanceVersicolor = 0;
    double distanceVirginica = 0;
    double distanceSetosa = 0;

    distanceVersicolor = pow(checkIris.sepalLength - irisAveVersicolor->sepalLength, 2) + pow(checkIris.sepalWidth - irisAveVersicolor->sepalWidth, 2) + pow(checkIris.petalLength - irisAveVersicolor->petalLength, 2) + pow(checkIris.petalWidth - irisAveVersicolor->petalWidth, 2);
    distanceVirginica = pow(checkIris.sepalLength - irisAveVirginica->sepalLength, 2) + pow(checkIris.sepalWidth - irisAveVirginica->sepalWidth, 2) + pow(checkIris.petalLength - irisAveVirginica->petalLength, 2) + pow(checkIris.petalWidth - irisAveVirginica->petalWidth, 2);
    distanceSetosa = pow(checkIris.sepalLength - irisAveSetosa->sepalLength, 2) + pow(checkIris.sepalWidth - irisAveSetosa->sepalWidth, 2) + pow(checkIris.petalLength - irisAveSetosa->petalLength, 2) + pow(checkIris.petalWidth - irisAveSetosa->petalWidth, 2);

    if(distanceVersicolor < distanceVirginica && distanceVersicolor < distanceSetosa){
        printf("versicolor\n");
    }else if(distanceVirginica < distanceVersicolor && distanceVirginica < distanceSetosa){
        printf("virginica\n");
    }else if(distanceSetosa < distanceVersicolor && distanceSetosa < distanceVirginica){
        printf("setosa\n");
    }else{
        printf("error\n");
    }

    return ;
}

void printIrisJudgementBySample(Iris *iris_lists ,int size , Iris checkIris){
    //　サンプルを用いて、どの種類に属するかを判定する。

    for(int i=0;i<size;i++){
        
    }

    return ;
}

int main(int argc, const char* argv[]){

    Iris lists[MAX];
    int size = 0;
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
    size = i;

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

    printIris(aveVersicolor);
    printIris(aveVirginica);
    printIris(aveSetosa);

    // リストで標準偏差を出す。
    printf("＝＝＝標準偏差＝＝＝\n");
    Iris stdVirginica = getIrisStandardDeviation(iris_virginica_list, iris_virginica_count);
    Iris stdVersicolor = getIrisStandardDeviation(iris_versicolor_list, iris_versicolor_count);
    Iris stdSetosa = getIrisStandardDeviation(iris_setosa_list, iris_setosa_count);
    
    printIris(stdVersicolor);
    printIris(stdVirginica);
    printIris(stdSetosa);

    // どのクラスに属しているのか判定する。
    Iris irisJudgment1 = {5.7,4.0,1.2,0.2,""};
    Iris irisJudgment2 = {5.9,2.9,4.2,1.5,""};
    Iris irisJudgment3 = {5.6,2.8,4.8,2.0,""};


    printf("＝＝＝判定1＝＝＝\n");
    printf("sample1: ");
    printIrisJudgementByAve(&aveVersicolor,&aveVirginica,&aveSetosa,irisJudgment1);
    printf("sample2: ");
    printIrisJudgementByAve(&aveVersicolor,&aveVirginica,&aveSetosa,irisJudgment2);
    printf("sample3: ");
    printIrisJudgementByAve(&aveVersicolor,&aveVirginica,&aveSetosa,irisJudgment3);

    // printf("＝＝＝判定2＝＝＝\n");
    // printIrisJudgementBySample(lists,size ,irisJudgment1);




    fclose(fp);

    return 0;
}