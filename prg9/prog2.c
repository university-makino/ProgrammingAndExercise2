#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, const char* argv[]){

    char date[] = "2011,1,1,41.085667,141.266667,1";
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

    printEarthquake(earthquake1);


    return 0;
}