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

    // latitudeの値でソートする
    for(int i=0; i<index; i++){
        for(int j=i+1; j<index; j++){
            if(earthquakeList[i].latitude > earthquakeList[j].latitude){
                Earthquake temp = earthquakeList[i];
                earthquakeList[i] = earthquakeList[j];
                earthquakeList[j] = temp;
            }
        }
    }

    int countList[360] = {0};
    for(int i = 0; i < 360 ; i+=2){
        for(int j = 0; j < index; j++){
            if(earthquakeList[j].latitude >= i && earthquakeList[j].latitude < i+2){
                // printEarthquake(earthquakeList[i]);
                countList[i]++;
            }
        }
    }

    printf("latitude, count\n");
    for(int i = 0; i < 360 ; i+=2){
        if(countList[i] != 0) printf("%d-%d: %d\n", i, i+1, countList[i]);
    }
    
    free(earthquakeList);
    fclose(fp);



    return 0;
}