#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Structure for queue with HD
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    // Storage for vertical lines
    int result[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX;  // To handle negative HD
    int minHD = 0, maxHD = 0;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* node = p.node;
        int hd = p.hd;

        int index = hd + offset;

        result[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}