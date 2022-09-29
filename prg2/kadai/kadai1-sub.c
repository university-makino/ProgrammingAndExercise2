#include <stdio.h>

extern char ss[256]; 

void yomiage(long long n){

    int indexNum = 0;
    while(n){
        //変換したい数値を16で割った余りを取得
        int bit = n % 10000;
        
        //余りを文字に変換
        ss[indexNum] = fixChineseNumeral(bit%1000);
        indexNum++;
        ss[indexNum] = "千";
        indexNum++;

        bit /= 1000;

        ss[indexNum] = fixChineseNumeral(bit%100);
        indexNum++;
        ss[indexNum] = "百";
        indexNum++;

        bit /= 100;

        ss[indexNum] = fixChineseNumeral(bit%10);
        indexNum++;
        ss[indexNum] = "十";
        indexNum++;

        bit /= 10;

        ss[indexNum] = fixChineseNumeral(bit);
        indexNum++;

        //次のビットを選択するために16で割る
        n /= 10000;
    }
}

char fixChineseNumeral(int num){
    switch(num){
        case 1: printf("一"); break;
        case 2: printf("二"); break;
        case 3: printf("三"); break;
        case 4: printf("四"); break;
        case 5: printf("五"); break;
        case 6: printf("六"); break;
        case 7: printf("七"); break;
        case 8: printf("八"); break;
        case 9: printf("九"); break;
    }
}