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

    Iris *lists;

    

    printIris(iris);

    return 0;
}