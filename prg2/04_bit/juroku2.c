#include <stdio.h>

char fixBit(int num);

int main(int argc, const char* argv[]){

    //変換したい数値を入力
    unsigned int num = 0;
    printf("input number: ");
    scanf("%d", &num);

    //結果を保存する部分を作成
    char result[255] = {'\0'};

    int indexNum = 0;
    while(num){
        //変換したい数値を16で割った余りを取得
        int bit = num % 16;
        
        //余りを文字に変換
        result[indexNum] = fixBit(bit);
        //配列を進める
        indexNum++;

        //次のビットを選択するために16で割る
        num /= 16;
    }

    //結果を表示
    for(int i = indexNum - 1; i >= 0; i--){
        printf("%c", result[i]);
    }
    printf("\n");


    return 0;
}

char fixBit(int num){
    if(num < 10){
        return num + '0';
    }else{
        return num - 10 + 'A';
    }
}