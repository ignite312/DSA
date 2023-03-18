#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
void preorder(struct Node* node) {
  if (node == NULL) return;
  cout << node->data << " ";
  preorder(node->left);
  preorder(node->right);
}
void postorder(struct Node* node) {
  if (node == NULL) return;
  postorder(node->left);
  postorder(node->right);
  cout << node->data << " ";
}
void inorder(struct Node* node) {
  if (node == NULL) return;
  inorder(node->left);
  cout << node->data << " ";
  inorder(node->right);
}
struct Node* newNode(int key) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}
struct Node* insertNode(struct Node* node, int key) {
    if(node == NULL) return newNode(key);
    if(key < node->data)node->left = insertNode(node->left, key);
    else node->right = insertNode(node->right, key);
    return node;
}
struct Node* inorderSuccessor(struct Node* node) {
    while(node->left) {
        node = node->left;
    }
    return node;
}
struct Node* deleteNode(struct Node* node, int key) {
    if(node == NULL)return node;
    if(key < node->data)node->left = deleteNode(node->left, key);
    else if(key > node->data)node->right = deleteNode(node->right, key);
    else {
        if(node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        }else if(node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        struct Node* temp = inorderSuccessor(temp->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, key);
    }
    return node;
}
int main() {
    struct Node* root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = insertNode(root, key);
    }
    deleteNode(root, 3);
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
}
