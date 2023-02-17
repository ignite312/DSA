#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next, *prev;
};
void insert_front(struct Node** head_ref, int value) {
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->next = *head_ref;
	new_node->prev = NULL;
	if(*head_ref != NULL)(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
void insert_after(struct Node* prev_node, int value) {
	if(prev_node == NULL)return;
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	if(new_node->next != NULL)new_node->next->prev = new_node;
}
void insert_back(struct Node** head_ref, int value) {
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if(*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	struct Node* temp = *head_ref;
	while(temp->next != NULL)temp = temp->next;
	new_node->prev = temp;
	temp->next = new_node;
}
bool search(struct Node* node, int key) {
	while(node != NULL) {
		if(node->data == key)return true;
		node = node->next;
	}
	return false;
}
void display(struct Node* node) {
	while(node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}
void delete_node(struct Node** head_ref, struct Node* target) {
	if(*head_ref == NULL || target == NULL) return;
	if(*head_ref == target)*head_ref = target->next;
	if(target->next != NULL)target->next->prev = target->prev;
	if(target->prev != NULL)target->prev->next = target->next;

}
void sort(struct Node* current) {
	struct Node* flag;
	int temp;
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
	display(head);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert_front(&head, x);
	}
	display(head);
	cout << search(head, 7) << "\n";
	delete_node(&head, head->next->next->next);
	cout << search(head, 7) << "\n";
	display(head);
	sort(head);
	display(head);
}
