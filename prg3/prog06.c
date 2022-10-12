#include <stdio.h>

void swap(int *x, int *y){
    int  work;        /* 作業用 */

    work = *x;        /* xの値を一時保存 */
    *x = *y;          /* xの値をyの値に書き換える */
    *y = work;        /* yの値をxの値に書き換える */
}


void sort(int *x, int *y){
    if(*x > *y){
        swap(x,y);
    }
}

void threeSort(int *x, int *y, int *z){
    sort(x,y);
    sort(y,z);
    sort(x,y);
}

int main(void){
    int x = 0;
    int y = 0;
    int z = 0;

    printf("(x,y,z) => ");
    scanf("%d %d %d",&x,&y,&z);

    printf("交換前: x = %d   y = %d  z = %d\n", x, y ,z);

    threeSort(&x, &y, &z);               
    printf("交換後: x = %d   y = %d  z = %d\n", x, y ,z);
}