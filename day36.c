#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int front = 0, rear = -1;

    // Enqueue n elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % n;
        arr[rear] = x;
    }

    int m;
    scanf("%d", &m);

    // Dequeue m elements
    for(int i = 0; i < m; i++) {
        front = (front + 1) % n;
    }

    // Number of remaining elements
    int count = n - m;

    // Display circular queue
    for(int i = 0; i < count; i++) {
        int index = (front + i) % n;
        printf("%d ", arr[index]);
    }

    return 0;
}