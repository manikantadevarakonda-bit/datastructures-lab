#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int N, i;
    struct Employee *employees;
    printf("Enter the number of employees (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input for N. Exiting.\n");
        return 1;
    }
    employees = (struct Employee *)malloc(N * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }
    printf("\nEnter employee details:\n");
    for (i = 0; i < N; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &(employees[i].id));
        while (getchar() != '\n'); 
        printf("Enter Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        for (int j = 0; j < sizeof(employees[i].name); j++) {
            if (employees[i].name[j] == '\n') {
                employees[i].name[j] = '\0';
                break;
            }
        }
        printf("Enter Salary: ");
        scanf("%f", &(employees[i].salary));
    }
    printf("\n--- Employee Information ---\n");
    for (i = 0; i < N; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
    }
    free(employees);
    printf("\nMemory freed successfully.\n");
    return 0;
}
