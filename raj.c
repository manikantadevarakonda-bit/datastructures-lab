#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtPosition(int value, int pos) {
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void displayList() {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int N, value, M;
    if (scanf("%d", &N) != 1) return 1;
    struct Node* last = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    last->next = head; 
    if (scanf("%d %d", &value, &M) != 2) return 1;
    insertAtPosition(value, M);
    displayList();
    return 0;
}
