#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
void preorder(struct Node* root) {
  if(root == NULL) return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(struct Node* root) {
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
void inorder(struct Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
struct Node* newNode(int key) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}
struct Node* insertNode(struct Node* root, int key) {
    if(root == NULL) return newNode(key);
    if(key < root->data)root->left = insertNode(root->left, key);
    else root->right = insertNode(root->right, key);
    return root;
}
struct Node* inorderSuccessor(struct Node* root) {
    while(root->left) root = root->left;
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (root->data < key) return search(root->right, key); 
    return search(root->left, key);
}
struct Node* deleteNode(struct Node* root, int key) {
    if(root == NULL)return root;
    if(key < root->data)root->left = deleteNode(root->left, key);
    else if(key > root->data)root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    deleteNode(root, 10);
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << (search(root, 12) == NULL ? "Not Found" : "Found") << "\n";
}
