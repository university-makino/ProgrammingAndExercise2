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
    struct student s1 = {"test", 20, "123456", 3};
    struct student s2 = {"test2", 21, "1234567", 4};
    struct student s3 = {"test3", 22, "12345678", 5};
    struct student s4 = {"test4", 23, "123456789", 6};

    printStudent(s1);
    printStudent(s2);
    printStudent(s3);
    printStudent(s4);

    return 0;
}   