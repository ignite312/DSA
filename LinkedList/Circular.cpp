#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
struct Node* insert_empty(struct Node* last, int value) {
	if(last != NULL)return last;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = new_node;
	return new_node;
} 
struct Node* insert_front(struct Node* last, int value) {
	if(last == NULL)return insert_empty(last, value);
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = last->next;
	last->next = new_node;
	return last;
}
struct Node* insert_after(struct Node* last, int key, int value) {
	if(last == NULL)return NULL;

	struct Node* temp = last->next, *new_node;
	do {
		if(temp->data == key) {
			new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->data = value;
			new_node->next = temp->next;
			temp->next = new_node;
			if(temp == last) return new_node;
		}
		temp = temp->next;
	}while(temp != last->next);
	return last;
}
struct Node* insert_back(struct Node* last, int value) {
	if(last == NULL)return insert_empty(last, value);
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = last->next;
	last->next = new_node;
	return new_node;
}
bool search(struct Node* last, int key) {
	if(last == NULL)return false;
	struct Node* node = last->next;
	do {
		if(node->data == key)return true;
		node = node->next;
	}while(node != last->next);
	return false;
}
void display(struct Node* last) {
	if(last == NULL)return;
	struct Node* node = last->next;
	do {
		cout << node->data << " ";
		node = node->next;
	}while(node != last->next);
	cout << '\n';
}
void sort(struct Node* last) {
	struct Node* current = last->next, *flag;
	int temp;
	do {
		flag = current->next;
		while(flag != last->next) {
			if(current->data > flag->data) {
				temp = current->data;
				current->data = flag->data;
				flag->data = temp;
			}
			flag = flag->next;
		}
		current = current->next;
	}while(current != last->next);
}
void delete_node(struct Node** last, int key) {
	if(*last == NULL)return;
	if((*last)->data == key && (*last)->next == *last) {
		free(last);
		*last = NULL;
		return;
	}
	struct Node* temp = *last, *del;
	if((*last)->data == key) {
		while(temp->next != *last)temp = temp->next;
		temp->next = (*last)->next;
		free(*last);
		*last = temp->next;
		return;
	}
	while(temp->next != *last && temp->next->data != key)temp = temp->next;
	if(temp->next->data == key) {
		del = temp->next;
		temp->next = del->next;
		free(del);
	}
	return;
}
int main() {
	struct Node* last = NULL;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		last = insert_back(last, x);
	}
	display(last);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		last = insert_front(last, x);
	}
	last = insert_after(last, 6, 3301);
	display(last);
	sort(last);
	display(last);
	cout << search(last, 4) << "\n";
	delete_node(&last, 4);
	cout << search(last, 4) << "\n";
}
