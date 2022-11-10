//
//  main.c
//  prog5
//
//  Created by k18065kk on 2018/11/15.
//  Copyright © 2018年 k18065kk. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int main(int argc, const char * argv[]) {

    FILE *fp;
    fp=fopen("meibo.txt","r");
    if(fp==NULL){
        printf("Cannot open the file.\n");
        exit(0);
    }

    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        printf("%s\n",line);
    }
    
    fclose(fp);
    return 0;
}
