#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

typedef struct earthquake{
    int year;
    int month;
    int day;
    double latitude;
    double longitude;
    double earthquakeIntensity;
}Earthquake;

void printEarthquake(Earthquake earthquake){
    printf("year: %d, month: %d, day: %d, latitude: %f, longitude: %f, earthquakeIntensity: %f\n", earthquake.year, earthquake.month, earthquake.day, earthquake.latitude, earthquake.longitude, earthquake.earthquakeIntensity);
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
    earthquake1.earthquakeIntensity = atof(pointer);

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
    int i=0;
    while (fgets(line, MAX, fp) != NULL) {
        earthquakeList[i] = createEarthquake(line);
        
        // メモリーを確保する（動的に）
        earthquakeList = (Earthquake *)realloc(earthquakeList, (i+2) * sizeof(Earthquake));
        i++;
    }

    // ここからデータを操作する。

    for(int j=0;j<i;j++){
        if(earthquakeList[j].month == 3 && earthquakeList[j].day == 11){
            printEarthquake(earthquakeList[j]);
        }
    }
    







    free(earthquakeList);
    fclose(fp);


    return 0;
}