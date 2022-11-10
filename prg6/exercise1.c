#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUM 20

int swap_str_ptr(char **str1, char **str2) {
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
    return 0;
}

int sort_str_ptr(char **str1, char **str2) {
    int str1_len = strlen(*str1);
    int str2_len = strlen(*str2);

    if (str1_len > str2_len) {
        swap_str_ptr(str1, str2);
    }
    return 0;
}

int bubble_sort_str_ptr(char **str, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            sort_str_ptr(&str[j], &str[j + 1]);
        }
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    int i;
    long cpu_time;
    double sec;

    char *list[] = { 
        "マイケル・J・エヴァンス", 
        "カイル・L・ブラウン",
        "ジェイソン・M・ホーク",
        "アンドリュー・デ・ジョーンズ",
        "クリス・デル・アダムス",
        "リチャード・ドン・アレン",
        "ジェイソン・アレン",
        "ケヴィン・デヴィッド・オニール",
        "ホリス・J・ナイト",
        "C・アール・ウルフ",
        "ロバート・アントン・スタインハウアー",
        "トム・デビッド・ベルトラン",
        "カール・マイケル・クイグリー",
        "リッチー・ウィリアムス・ベネット",
        "リチャード・ドン・アレン",
        "チャールズ・ウィアー・ラトリフ",
        "サン・リー・スペイディア",
        "マイケル・J・エヴァンス",
        "グレゴリー・J・カルホーン",
        "ケイド・J・ミネリ"
    };

    printf("=== old ==== \n");
    for (int i = 0; i < NUM; i++) {
        printf("list[%d] = %s\n", i, list[i]);
    }

    bubble_sort_str_ptr(list, NUM);

    printf("=== new ==== \n");
    for (int i = 0; i < NUM; i++) {
        printf("list[%d] = %s\n", i, list[i]);
    }

    /* CPU時間をチェック */
    cpu_time = clock();

    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;

    printf("%f秒\n", sec);

    return 0;
}