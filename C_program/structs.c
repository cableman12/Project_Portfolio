#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main()
{
    struct Student student1;
    student1.age = 20;
    student1.gpa = 3.5;
    strcpy(student1.name, "John Doe");
    strcpy(student1.major, "Computer Science");

    printf("Name: %s\n", student1.name);
    printf("Major: %s\n", student1.major);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);
    return 0;
}