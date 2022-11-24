#include <stdio.h>

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

    Iris iris1 = {6.7, 3.0, 5.2, 2.3, "Iris-virginica"};
    Iris iris2 = {7.0, 3.2, 4.7, 1.4, "Iris-versicolor"};

    printIris(iris1);
    printIris(iris2);

    return 0;
}