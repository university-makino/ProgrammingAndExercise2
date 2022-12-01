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
    int i=0;
    while (fgets(line, MAX, fp) != NULL) {
        earthquakeList[i] = createEarthquake(line);
        
        // メモリーを確保する（動的に）
        earthquakeList = (Earthquake *)realloc(earthquakeList, (i+2) * sizeof(Earthquake));
        i++;
    }

    // ここからデータを操作する。

    int dateOfEachMonthList [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int earthquakeCountList [365] = {0};
    int currentMonth = 1;
    int currentDay = 1;
    int dayCount = 0;

    for(int j=0;j<i;j++){

        if(currentMonth == earthquakeList[j].month){
            if(currentDay == earthquakeList[j].day){
                earthquakeCountList[dayCount]++;
            }else{
                currentDay++;
                dayCount++;
            }
        }else if(currentDay == dateOfEachMonthList[currentMonth-1]){
            currentMonth++;
            currentDay = 0;
        }else{
            currentDay++;
            dayCount++;
        }
    }

    double ave = i / 365.0;

    //SD
    double SD = 0;
    for(int j=0;j<365;j++){
        SD += (earthquakeCountList[j] - ave) * (earthquakeCountList[j] - ave);
    }
    SD = SD / 365;
    SD = sqrt(SD);
    printf("SD: %f\n", SD);

    // 各日付の確認用
    // int index = 0;
    // for(int j=0;j<12;j++){
    //     for(int k=0;k<dateOfEachMonthList[j];k++){
    //         printf("%d月%d日: %d\n", j+1, k+1, earthquakeCountList[index]);
    //         index++;
    //     }
    // }

    printf("average: %f\n", ave);
    
    free(earthquakeList);
    fclose(fp);


    return 0;
}