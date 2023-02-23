#include<bits/stdc++.h>
using namespace std;

struct StackNode {
	int data;
	struct StackNode* next;
};
bool empty(struct StackNode* node) {
	return !node;
}
void push(struct StackNode** root, int value) {
	struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
	new_node->data = value;
	new_node->next = *root;
	(*root) = new_node;
	cout << value << " Pushed into Stack\n";
}
void pop(struct StackNode** root) {
	if(empty(*root)) {
		cout << "Stack Underflow\n";
		return;
	}
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	cout << popped << " Popped from  Stack\n";
}
void top(struct StackNode* root) {
	if(empty(root)) {
		cout << "Stack is Empty\n";
		return;
	}
	cout << "Top element: " << root->data << "\n";
}
int main() {
	struct StackNode* root = NULL;
	push(&root, 1);
	push(&root, 2);
	push(&root, 3);
	cout << (empty(root) ? "Stack is Empty\n" : "Stack isn't Empty\n");
	top(root);
	pop(&root);
	pop(&root);
	pop(&root);
	pop(&root);
	cout << (empty(root) ? "Stack is Empty\n" : "Stack isn't Empty\n");
}
