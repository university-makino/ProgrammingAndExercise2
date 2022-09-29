#include <stdio.h>
#include <stdlib.h> 

extern void yomiage(long long n); 
char ss[256] = {'\0'}; 


int main() { 
    // 文字列は charの配列 (詳細は後日) 
    // int よりも大きい整数値を扱える型
    // (詳しくは 各自で 調べなさい) 
    long long n = 0; 
    

    printf("Number ? ");     
    // 数値を文字列として入力し
    // さらに 数値に変換する処理のコード
    fgets(ss, sizeof(ss), stdin); 
    n = atoll(ss); 
    
    printf("%lld = ", n); 
    yomiage(n); 
    printf("\n");
    return 0; 
    // long long 型の場合 「%d」ではなく
    // 「%lld」とする (詳細は 各自調べよ) 
}

//1,0000,0000,0000
