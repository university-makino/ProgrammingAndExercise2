#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256


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

    Iris *lists;
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("iris.data", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    while (fgets(line, MAX, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    // printIris(iris);

    return 0;
}