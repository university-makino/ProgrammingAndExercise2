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

    //推定を行う
    int miss = 0;
    CurrentIris result;

    for (int k=0; k < DIVISION; k++){
        Iris array_test[size/DIVISION];
        Iris array_learn[size - (size/DIVISION)];

        //テスト用の配列を作成
        for(int i=0; i < size/DIVISION ;i++){
            array_test[i] = irisList[k][i];
        }

        //学習用の配列を作成
        int index = 0;
        for(int i=0; i < DIVISION ;i++){
            if(i != k){
                for(int j=0; j < size/DIVISION ;j++){
                    array_learn[index] = irisList[i][j];
                    index++;
                }
            }
        }

        for(int i=0; i < size/DIVISION ;i++){

            double smallDistance = 100;
            Iris nearDate;

            for(int j=0;j< size - (size/DIVISION) ;j++){
                double distance = irisDistance(array_test[i],array_learn[j]);
                if(distance < smallDistance){
                    smallDistance = distance;
                    nearDate = array_learn[j];
                }
            }

            if(strcmp(nearDate.species,"Iris-virginica") == 0){
                if(strcmp(array_test[i].species,"Iris-virginica") == 0){
                    result.currentVirginica.estimateVirginica++;
                }else if(strcmp(array_test[i].species,"Iris-versicolor") == 0){
                    result.currentVirginica.estimateVersicolor++;
                }else if(strcmp(array_test[i].species,"Iris-setosa") == 0){
                    result.currentVirginica.estimateSetosa++;
                }   
            }else if(strcmp(nearDate.species,"Iris-versicolor") == 0){
                if(strcmp(array_test[i].species,"Iris-virginica") == 0){
                    result.currentVersicolor.estimateVirginica++;
                }else if(strcmp(array_test[i].species,"Iris-versicolor") == 0){
                    result.currentVersicolor.estimateVersicolor++;
                }else if(strcmp(array_test[i].species,"Iris-setosa") == 0){
                    result.currentVersicolor.estimateSetosa++;
                }
            }else if(strcmp(nearDate.species,"Iris-setosa") == 0){
                if(strcmp(array_test[i].species,"Iris-virginica") == 0){
                    result.currentSetosa.estimateVirginica++;
                }else if(strcmp(array_test[i].species,"Iris-versicolor") == 0){
                    result.currentSetosa.estimateVersicolor++;
                }else if(strcmp(array_test[i].species,"Iris-setosa") == 0){
                    result.currentSetosa.estimateSetosa++;
                }
            }
        }
    }
    

    printf("横：推定結果　縦：正解 (正解数)\n\n");
    printf("          virginica , versicolor , setosa\n");
    printf("virginica : %02.0f       , %02.0f         , %02.0f\n",result.currentVirginica.estimateVirginica,result.currentVirginica.estimateVersicolor,result.currentVirginica.estimateSetosa);
    printf("versicolor: %02.0f       , %02.0f         , %02.0f\n",result.currentVersicolor.estimateVirginica,result.currentVersicolor.estimateVersicolor,result.currentVersicolor.estimateSetosa);
    printf("setosa    : %02.0f       , %02.0f         , %02.0f\n",result.currentSetosa.estimateVirginica,result.currentSetosa.estimateVersicolor,result.currentSetosa.estimateSetosa);

    int currentSetosa = result.currentSetosa.estimateSetosa + result.currentSetosa.estimateVersicolor + result.currentSetosa.estimateVirginica;
    int currentVersicolor = result.currentVersicolor.estimateSetosa + result.currentVersicolor.estimateVersicolor + result.currentVersicolor.estimateVirginica;
    int currentVirginica = result.currentVirginica.estimateSetosa + result.currentVirginica.estimateVersicolor + result.currentVirginica.estimateVirginica;

    result.currentSetosa.estimateSetosa =  result.currentSetosa.estimateSetosa / currentSetosa * 100;
    result.currentSetosa.estimateVersicolor =  result.currentSetosa.estimateVersicolor / currentSetosa * 100;
    result.currentSetosa.estimateVirginica =  result.currentSetosa.estimateVirginica / currentSetosa * 100;
    result.currentVersicolor.estimateSetosa =  result.currentVersicolor.estimateSetosa / currentVersicolor * 100;
    result.currentVersicolor.estimateVersicolor =  result.currentVersicolor.estimateVersicolor / currentVersicolor * 100;
    result.currentVersicolor.estimateVirginica =  result.currentVersicolor.estimateVirginica / currentVersicolor * 100;
    result.currentVirginica.estimateSetosa =  result.currentVirginica.estimateSetosa / currentVirginica * 100;
    result.currentVirginica.estimateVersicolor =  result.currentVirginica.estimateVersicolor / currentVirginica * 100;
    result.currentVirginica.estimateVirginica =  result.currentVirginica.estimateVirginica / currentVirginica * 100;


    printf("\n\n横：推定結果　縦：正解　（正解割合）\n\n");
    printf("          virginica , versicolor , setosa\n");
    printf("virginica : %03.2f %%       , %03.2f %%         , %03.2f %%\n",result.currentVirginica.estimateVirginica,result.currentVirginica.estimateVersicolor,result.currentVirginica.estimateSetosa);
    printf("versicolor: %03.2f %%       , %03.2f %%         , %03.2f %%\n",result.currentVersicolor.estimateVirginica,result.currentVersicolor.estimateVersicolor,result.currentVersicolor.estimateSetosa);
    printf("setosa    : %03.2f %%       , %03.2f %%         , %03.2f %%\n",result.currentSetosa.estimateVirginica,result.currentSetosa.estimateVersicolor,result.currentSetosa.estimateSetosa);


    fclose(fp);
    return 0;
}