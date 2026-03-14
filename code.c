#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* add_to_empty(struct Node* last, int data) {
    if (last != NULL) return last;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    last = newNode;
    last->next = last; 
    return last;
}
struct Node* insert_end(struct Node* last, int data) {
    if (last == NULL) return add_to_empty(last, data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}
struct Node* remove_last(struct Node* last) {
    if (last == NULL) {
        return NULL; 
    }
    if (last->next == last) {
        free(last);
        return NULL;
    }
    struct Node* temp = last->next;
    struct Node* prev = NULL;
    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = last->next;
    free(last);
    last = prev;
    return last;
}
void traverse(struct Node* last) {
    if (last == NULL) {
        return; 
    }
    struct Node* p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
}
int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 1;
    struct Node* last = NULL;
    int data;
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        last = insert_end(last, data);
    }
    last = remove_last(last);
    traverse(last);
    printf("\n");
    return 0;
}
