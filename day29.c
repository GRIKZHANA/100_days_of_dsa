#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    // Step 1: find length
    int n = 1;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: reduce k
    k = k % n;
    if (k == 0)
        return head;

    // Step 3: make circular
    temp->next = head;

    // Step 4: find new tail (n-k-1 steps from head)
    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: set new head and break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}