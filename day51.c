#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// LCA function
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root; // split point
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Input BST
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca)
        printf("%d\n", lca->data);

    return 0;
}