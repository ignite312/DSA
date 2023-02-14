#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
void insert_back(struct Node** head_ref, int value) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head_ref;
	new_node->data = value;
	new_node->next = NULL;
	if(*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL) last = last->next;
	last->next = new_node;
}
void insert_front(struct Node** head_ref, int value) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void insert_after(struct Node* prev_node, int value) {
	if(prev_node == NULL)return;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = prev_node;
    prev_node->next = new_node;
}
bool search_node(struct Node* node, int key) {
	while(node != NULL) {
		if(node->data == key)return true;
		node = node->next;
	}
	return false;
}
void delete_node(struct Node** head_ref, int key) {
	struct Node* temp = *head_ref;
	struct Node* prev;
	if(temp != NULL && temp->data == key) {
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL) return;
	prev->next = temp->next;
	free(temp);
}
void display(struct Node* node) {
	while(node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}
void sort(struct Node** head_ref) {
	struct Node* current = *head_ref, *flag;
	int temp;
	if(current == NULL) return;
	while(current != NULL) {
		flag = current->next;
		while(flag != NULL) {
			if(current->data > flag->data) {
				temp = current->data;
				current->data = flag->data;
				flag->data = temp;
			}
			flag = flag->next;
		}
		current = current->next;
	}
}
int main() {
	struct Node* head = NULL;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert_back(&head, x);
	}
	insert_front(&head, 1);
	insert_front(&head, 2);
	insert_front(&head, 3);
	display(head);
	cout << search_node(head, 5) << "\n";
	delete_node(&head, 5);
	display(head);
	sort(&head);
	display(head);
	cout << search_node(head, 5) << "\n";
}
