#include <stdio.h>
#include <stdlib.h>

typedef struct trial{
    int speed;
    int distance;
}Trial;

void dispTrial(Trial *t){
    printf("speed: %d, distance: %d\n", t->speed, t->distance);
}

int main(int argc, const char* argv[]){

    char line[]="10,18\n";
    Trial t;

    sscanf(line, "%d,%d", &t.speed, &t.distance);

    dispTrial(&t);

    return 0;
}