#include <stdio.h>
struct student {
    char name[50];
    int age;
    float total_marks;
};
int main() {
    struct student s1, s2;
    float average_marks;
    printf("Enter information for the first student:\n");
    printf("Name: ");
    scanf("%s", s1.name);
    printf("Age: ");
    scanf("%d", &s1.age);
    printf("Total marks: ");
    scanf("%f", &s1.total_marks);
    printf("\nEnter information for the second student:\n");
    printf("Name: ");
    scanf("%s", s2.name);
    printf("Age: ");
    scanf("%d", &s2.age);
    printf("Total marks: ");
    scanf("%f", &s2.total_marks);
    printf("\n--- Displaying Student Information ---\n");
    printf("Student 1:\n");
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Total marks: %.2f\n", s1.total_marks);
    printf("\nStudent 2:\n");
    printf("Name: %s\n", s2.name);
    printf("Age: %d\n", s2.age);
    printf("Total marks: %.2f\n", s2.total_marks);
    average_marks = (s1.total_marks + s2.total_marks) / 2.0;
    printf("\nAverage of total marks for both students: %.2f\n", average_marks);
    return 0; 
}
