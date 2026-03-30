#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

// Define queue
struct Queue {
    struct Node *front, *rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    while (n--) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        }
        else if (choice == 2) {
            dequeue(q);
        }
    }

    return 0;
}