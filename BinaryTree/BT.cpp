#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *newNode(int data) {
  struct Node *Node = (struct Node *)malloc(sizeof(struct Node));

  Node->data = data;

  Node->left = NULL;
  Node->right = NULL;
  return (Node);
}
void inorder(struct Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
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
int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  preorder(root);
  cout << "\n";
  inorder(root);
  cout << "\n";
  postorder(root);
}
