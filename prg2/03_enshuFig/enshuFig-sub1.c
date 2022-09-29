#include <stdio.h>

int draw_figure(int n){

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}