#include <stdio.h>

void badSwap(int p, int q);
void goodSwap(int *p, int *q);

int main(int argc, const char * argv[]) {
    int a,b;
    a=1;
    b=2;
    printf("a=%d,b=%d\n",a,b);
    badSwap(a, b);
    printf("bad → a=%d,b=%d\n",a,b);
    goodSwap(&a, &b);
    printf("good → a=%d,b=%d\n",a,b);
    return 0;
}

void badSwap(int p, int q){
    int tmp;
    tmp=p;
    p=q;
    q=tmp;
}

void goodSwap(int *p, int *q){
    int tmp;
    tmp=*p;
    *p=*q;
    *q=tmp;
}