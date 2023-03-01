#include<bits/stdc++.h>
using namespace std;
const int MX = 100;

class Queue {
    int arr[MX];
    int front, rear, sz;
public:
    Queue() {
        front = rear = -1;
        sz = 0;
    }
    int get_front() {
        if(front != -1) return arr[front];
        cout << "Stack is empty\n";
    }
    int get_back() {
        if(rear != -1)return arr[rear];
        cout << "Stack is Empty\n";
    }
    bool empty() {
        return (front == -1);
    }
    int size() {
        return sz;
    }
    void push(int value) {
        if(empty())front = rear = 0;
        else rear++;
        arr[rear] = value;
        sz++;
        cout << value << " Pushed into Stack\n";
    }
    void pop() {
        if(empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        sz--;
        if(front == rear)front = rear = -1;
        else front++;
    }
    void display() {
        if(empty()) {
            cout << "Queue Empty\n";
            return;
        }
        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    cout << "Total Size: " << q.size() << "\n";
    cout << q.empty() << "\n";
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.empty() << "\n";
    cout << "Total Size: " << q.size() << "\n";
}
