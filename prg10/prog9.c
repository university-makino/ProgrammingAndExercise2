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
    int i=0;
    while (fgets(line, MAX, fp) != NULL) {
        earthquakeList[i] = createEarthquake(line);
        
        // メモリーを確保する（動的に）
        earthquakeList = (Earthquake *)realloc(earthquakeList, (i+2) * sizeof(Earthquake));
        i++;
    }

    // ここからデータを操作する。
    int earthquakeIntensityCount[16] = {0};
    for(int j=0;j<i;j++){
        if(
            earthquakeList[j].earthquakeIntensity != 'A' &&
            earthquakeList[j].earthquakeIntensity != 'B' && 
            earthquakeList[j].earthquakeIntensity != 'C' &&
            earthquakeList[j].earthquakeIntensity != 'D' 
        ){
            earthquakeIntensityCount[earthquakeList[j].earthquakeIntensity - '0']++;
        }else{
            int index = earthquakeList[j].earthquakeIntensity - 'A' + 10;
            earthquakeIntensityCount[index]++;
        }
    }

    //16進数で出力する。

    // for(int j = 1; j < 16; j++){
    //     if(j < 10){
    //         printf("%d: %d\n", j, earthquakeIntensityCount[j]);
    //     }else{
    //         printf("%c: %d\n", j + 'A' - 10, earthquakeIntensityCount[j]);
    //     }
    // }

    // printfでベタ打ちする

    // printf("震度1: %d\n", earthquakeIntensityCount[1]);
    // printf("震度2: %d\n", earthquakeIntensityCount[2]);
    // printf("震度3: %d\n", earthquakeIntensityCount[3]);
    // printf("震度4: %d\n", earthquakeIntensityCount[4]);
    // printf("震度5弱: %d\n", earthquakeIntensityCount[10]);
    // printf("震度5強: %d\n", earthquakeIntensityCount[11]);
    // printf("震度6弱: %d\n", earthquakeIntensityCount[12]);
    // printf("震度6強: %d\n", earthquakeIntensityCount[13]);
    // printf("震度7: %d\n", earthquakeIntensityCount[7]);

    int earthquakeCount = earthquakeIntensityCount[10] + earthquakeIntensityCount[11] + earthquakeIntensityCount[12] + earthquakeIntensityCount[13] + earthquakeIntensityCount[7];
    printf("震度5弱以上の地震の回数: %d\n", earthquakeCount);

    free(earthquakeList);
    fclose(fp);


    return 0;
}