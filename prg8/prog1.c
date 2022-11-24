#include <stdio.h>

struct student {
    char *name;
    int age;
    char *id;
    int schoolYear;
};

void printStudent(struct student s){
    printf("Name: %s, Age: %d, ID: %s, School Year: %d\n", s.name, s.age, s.id, s.schoolYear);
    return ;
}

int main(int argc, const char* argv[]){
    struct student s1 = {"makino", 19, "k22130", 1};
    struct student s2 = {"owashiro", 20, "x21011", 2};
    struct student s3 = {"ogane", 21, "l20123", 3};
    struct student s4 = {"kawashima", 22, "b13123", 4};

    printStudent(s1);
    printStudent(s2);
    printStudent(s3);
    printStudent(s4);

    return 0;
}   