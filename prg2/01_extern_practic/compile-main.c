#include <stdio.h>
//プロトタイプ宣言//「extern」とは「別ファイルに定義本体があるよ」という意味
extern int sub(int);
int b;

int main(){
    b = 10;
    printf("%d\n", sub(5)); //別ファイルで定義される関数subを呼ぶ
}