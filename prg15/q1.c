#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){

    //ファイル読み込み
    FILE *fp;
    fp = fopen("cars.csv", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    char line[256];
    while(fgets(line, 256, fp) != NULL){
        int speed = 0;
        int distance = 0;
        sscanf(line, "%d,%d", &speed, &distance);

        printf("speed: %d, distance: %d\n", speed, distance);
    }

    return 0;
}