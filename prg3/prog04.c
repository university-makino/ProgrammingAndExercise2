#include <stdio.h>

void swap(int *x, int *y){
    int  work;        /* 作業用 */

    work = *x;        /* xの値を一時保存 */
    *x = *y;          /* xの値をyの値に書き換える */
    *y = work;        /* yの値をxの値に書き換える */
}

int main(void){
    int  x = 10, y = 20;         /* int型の変数の宣言 */
    int *px, *py;                /* int型のポインタ宣言 */ 

    printf("交換前: x = %d   y = %d\n", x, y);

    swap(&x, &y);               
    printf("交換後: x = %d   y = %d\n", x, y);
}