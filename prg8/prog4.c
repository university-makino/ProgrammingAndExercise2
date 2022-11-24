#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct iris {
    double sepalLength;
    double sepalWidth;
    double petalLength;
    double petalWidth;
    char *species;
}Iris;

void printIris(Iris iris){
    printf("sepalLength: %f, sepalWidth: %f, petalLength: %f, petalWidth: %f, species: %s\n", iris.sepalLength, iris.sepalWidth, iris.petalLength, iris.petalWidth, iris.species);
    return ;
}

int main(int argc, const char* argv[]){

    char line[50]="5.7,2.9,4.2,1.3,Iris-versicolor\n";
    char *pointer;
    Iris iris;
    
    //,を用いて文字列を分割
    //https://secret-garden.hatenablog.com/entry/2015/09/02/000000
    pointer = strtok(line, ",");

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
    iris.species = pointer;

    

    printIris(iris);

    return 0;
}