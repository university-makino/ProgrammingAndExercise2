#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    char *str1 = "hoge";
    char *str2 = "hage";

    if (strcmp(str1, str2) == 0) {
        printf("SAME\n");
    } else {
        printf("DIFF\n");
    }

    return 0;
}