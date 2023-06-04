#include <bits/stdc++.h> 
using namespace std;

class Queue{
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* front = NULL;
    struct Node* rear = NULL;
public:
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
};
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Total Size: " << q.size() << "\n";
    cout << q.empty() << "\n";
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.empty() << "\n";
    cout << "Total Size: " << q.size() << "\n";
}
