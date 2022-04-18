#include <stdio.h>

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
} student;

int main(){
    student a = {"kim", 20, 4.3};
    student b = {"part", 21, 4.2};
    
    printf("%s\t %d\t %f\n", a.name, a.age, a.gpa);
    printf("%s\t %d\t %f\n", b.name, b.age, b.gpa);
    
    return 0;
}