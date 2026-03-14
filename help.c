#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
void insertAtFront(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}
void printList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    int N, i, employeeId;
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    for (i = 0; i < N; i++) {
        if (scanf("%d", &employeeId) != 1) {
            break;
        }
        insertAtFront(employeeId);
        printf("Node Inserted\n");
        printList();
    }
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
