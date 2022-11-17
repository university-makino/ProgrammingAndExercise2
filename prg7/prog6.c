#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {

    char *str1 = "ABCDE";
    char *str2 = "XYZ";
    char *str;

    int len = strlen(str1) + strlen(str2) + 1;

    if ((str = (char *)malloc(len * sizeof(char))) == NULL) {
        printf("No enough memory.¥n");
        exit(1);
    }

    strcat(str,str1);
    strcat(str,str2);

    printf("%s\n",str);

    free(str);
    return 0;
}