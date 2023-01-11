char input[10];
            int number = 0 ;
            printf("入力 ");
            scanf("%[^\n]",input);//%[^\n]は改行が入るまで全てのデータを取得
            char *token = strtok(input," ");
            char *command = token;
            token = strtok(NULL," ");
            char *splitNumber = token;
            if(splitNumber!=NULL){//p or q の場合行わない
                number=atoi(splitNumber);
            }