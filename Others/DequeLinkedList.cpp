#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node* prev, *next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
int TotalSize = 0;

int get_front() {
    if(front == NULL)return -1;
    return front->data;
}
int get_back() {
    if(rear == NULL)return -1;
    return rear->data;
}
bool empty() {
    return !front;
}
int size() {
    return TotalSize;
}
void erase() {
    rear = NULL;
    while(front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
    TotalSize = 0;
}
void push_front(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = front;
    new_node->prev = NULL;
    TotalSize++;
    cout << value << " Pushed into Front\n";
    if(front == NULL) {
        front = rear = new_node;
        return;
    }
    front->prev = new_node;
    front = new_node;
}
void push_back(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = rear;
    TotalSize++;
    cout << value << " Pushed into Back\n";
    if(rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}
void pop_front() {
    if(front == NULL) {
        cout << "Queue UnderFlow\n";
        return;
    }
    struct Node* temp = front;
    front = front->next;
    int value = temp->data;
    if(front == NULL) rear = NULL;
    else front->prev = NULL;
    free(temp);
    TotalSize--;
    cout << value << " Popped from front\n";
}
void pop_back() {
    if(front == NULL) {
        cout << "Queue UnderFlow\n";
        return;
    }
    struct Node* temp = rear;
    rear = rear->prev;
    int value = temp->data;
    if(rear == NULL) front = NULL;
    else rear->next = NULL;
    free(temp);
    TotalSize--;
    cout << value << " Popped from back\n";
}
int main() {
    push_back(1);
    push_back(2);
    cout << "Total Size: " << size() << "\n";
    cout << (empty() ? "Empty" : "Not Empty") << "\n";
    push_front(7);
    push_front(8);
    cout << "Front element " << get_front() << "\n";
    cout << "Back element " << get_back() << "\n";
    pop_back();
    pop_front();
    pop_back();
    pop_front();
    pop_back();
    cout << "Total Size: " << size() << "\n";
    cout << (empty() ? "Empty" : "Not Empty") << "\n";
}
