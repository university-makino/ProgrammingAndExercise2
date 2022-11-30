#include <stdio.h>

typedef struct location {
    double latitude;
    double longitude;
    char *address;
}Location;

int main(int argc, const char* argv[]){

    Location aichiInstituteOfTechnology = {35.1834166, 137.1108532, "〒470-0356 愛知県豊田市八草町八千草１２４７"};
    Location aikodaiMeidenHighSchool = {35.1778635, 136.9464276, "〒464-0083 愛知県名古屋市千種区若水３丁目２−１２"};

    printf("愛知工業大学の緯度: %f, 経度: %f, 住所: %s\n", aichiInstituteOfTechnology.latitude, aichiInstituteOfTechnology.longitude, aichiInstituteOfTechnology.address);
    printf("愛工大名古屋校の緯度: %f, 経度: %f, 住所: %s\n", aikodaiMeidenHighSchool.latitude, aikodaiMeidenHighSchool.longitude, aikodaiMeidenHighSchool.address);

    return 0;
}