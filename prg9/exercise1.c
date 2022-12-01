#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 256

typedef struct earthquake{
    int year;
    int month;
    int day;
    double latitude;
    double longitude;
    char earthquakeIntensity;
}Earthquake;

void printEarthquake(Earthquake earthquake){
    printf("year: %d, month: %d, day: %d, latitude: %f, longitude: %f, earthquakeIntensity: %c\n", earthquake.year, earthquake.month, earthquake.day, earthquake.latitude, earthquake.longitude, earthquake.earthquakeIntensity);
    return ;
}

Earthquake createEarthquake(char date[MAX]){
    char *pointer;
    Earthquake earthquake1;

    pointer = strtok(date, ",");
    earthquake1.year = atoi(pointer);
    pointer = strtok(NULL, ",");
    earthquake1.month = atoi(pointer);
    pointer = strtok(NULL, ",");
    earthquake1.day = atoi(pointer);
    pointer = strtok(NULL, ",");
    earthquake1.latitude = atof(pointer);
    pointer = strtok(NULL, ",");
    earthquake1.longitude = atof(pointer);
    pointer = strtok(NULL, ",");
    earthquake1.earthquakeIntensity = pointer[0];

    return earthquake1;
}

int main(int argc, const char* argv[]){
    Earthquake *earthquakeList;
    //動的なリスト生成
    earthquakeList = (Earthquake *)malloc(5 * sizeof(Earthquake));
    char line[MAX];  // １⾏分を読み込むための配列

    FILE *fp;
    fp = fopen("h2011_eq.csv", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // ファイル処理をここに書く
    int index=0;
    while (fgets(line, MAX, fp) != NULL) {
        earthquakeList[index] = createEarthquake(line);
        
        // メモリーを確保する（動的に）
        earthquakeList = (Earthquake *)realloc(earthquakeList, (index+2) * sizeof(Earthquake));
        index++;
    }

    FILE *outputFile;
    outputFile = fopen("h2011_eq_lon_sort.csv", "w");
    if (outputFile == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    // longitude sort
    for (int i=0; i<index; i++) {
        for (int j=i+1; j<index; j++) {
            if (earthquakeList[i].longitude > earthquakeList[j].longitude) {
                Earthquake temp = earthquakeList[i];
                earthquakeList[i] = earthquakeList[j];
                earthquakeList[j] = temp;
            }
        }
    }

    for(int i=0; i<index; i++){
        fprintf(outputFile, "%d,%d,%d,%f,%f,%c\n", earthquakeList[i].year, earthquakeList[i].month, earthquakeList[i].day, earthquakeList[i].latitude, earthquakeList[i].longitude, earthquakeList[i].earthquakeIntensity);
    }
    
    free(earthquakeList);
    fclose(fp);
    fclose(outputFile);



    return 0;
}