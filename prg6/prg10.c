#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]){

    char str[128]="foo,bar,hoge,fuga";

    char *p = strtok(str, ",");
    while(p != NULL){
        printf("%s\n", p);
        p = strtok(NULL, ",");
    }



    return 0;
}