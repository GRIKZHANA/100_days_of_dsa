#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Get size
int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

// Push at front
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front > 0) {
        front--;
    } else {
        printf("Overflow at front\n");
        return;
    }
    deque[front] = x;
}

// Push at rear
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow at rear\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop from front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Pop from rear
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front element
void getFront() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[front]);
    }
}

// Get rear element
void getBack() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[rear]);
    }
}

int main() {
    // Example usage (you can modify input as needed)

    push_back(10);
    push_back(20);
    push_front(5);

    getFront();   // 5
    getBack();    // 20

    pop_front();  // 5
    pop_back();   // 20

    printf("%d\n", size()); // 1

    return 0;
}