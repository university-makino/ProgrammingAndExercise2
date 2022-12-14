#include <stdio.h>

int main(int argc, const char* argv[]){

    int x1 = 1;
    int ans = x1;

    for(int n = 2; n <= 10; n++){
        ans = ans + 2;
        // printf("%d\n", ans);
    }

    printf("%d\n", ans);

    return 0;
}