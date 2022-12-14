#include <stdio.h>
#include <math.h>

int main(int argc, const char* argv[]){

    int n = 10;
    int a = 4;
    int ans = 0;

    for(int k = 0; k <= n; k++){
        ans = ans + pow(a, n-k);
    }

    printf("%d\n", ans);

    return 0;
}