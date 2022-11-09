#include <stdio.h>
#include <ctype.h>

int main(int argc, const char* argv[]){

    char input[256] = {'\0'};

    printf("input: ");
    scanf("%s", input);

    printf("input: %s\n", input);

    //upper
    for(int i=0; i<256; i++){
        if(input[i] == '\0'){
            break;
        }
        input[i] = toupper(input[i]);
    }

    printf("upper: %s\n", input);



    return 0;
}