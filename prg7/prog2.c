#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {

    char *pointer = (char*)malloc(5 * sizeof(char));

    // pointer = "hoge" これはダメ。
    // "hoge"をしたタイミングで、hogeをどこか知らないアドレスに展開されて、その先頭のアドレスを突っ込まれるため、freeができなくなる。
    strcpy(pointer, "hoge");

    printf("pointer = %s\n", pointer);

    free(pointer);
    return 0;
}