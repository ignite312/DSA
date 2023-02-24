#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

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
    struct Node* temp = front;
    int sz = 0;
    while(temp != NULL) {
        sz++;
        temp = temp->next;
    }
    return sz++;
}
void push(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    cout << value << " Pushed into Queue\n";
    if(rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}
void pop() {
    if(front == NULL) {
        cout << "Queue UnderFlow\n";
        return;
    }
    struct Node* temp = front;
    int value = front->data;
    front = front->next;
    free(temp);
    cout << value << " Popped from Queue\n";
}
int main() {
    push(1);
    push(2);
    push(3);
    cout << "Total Size: " << size() << "\n";
    cout << empty() << "\n";
    pop();
    pop();
    pop();
    pop();
    cout << empty() << "\n";
    cout << "Total Size: " << size() << "\n";
}
