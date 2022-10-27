#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]){

    char *str = "abcd";

    int index = strlen(str);
    for (int i = 0; i < index; i++){
        printf("%c\n", str[i]);
    }

    return 0;
}