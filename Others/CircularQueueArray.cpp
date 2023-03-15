#include<bits/stdc++.h>
using namespace std;
const int Mx = 3;

class CircularQueue {
    int arr[Mx], front, rear, sz;

public:
    CircularQueue() {
        front = rear = -1;
        sz = 0;
    }
    bool empty() {
        return (front == -1);
    }
    int size() {
        return sz;
    }
    void erase() {
        front = rear = -1;
    }
    int get_front() {
        if(empty())cout << "Empty" << "\n";
        else cout << arr[front] << "\n";
    }
    int get_back() {
        if(empty())cout << "Empty" << "\n";
        else cout << arr[rear] << "\n";
    }
    void push(int value) {
        if((rear + 1) % Mx == front)cout << "Overflow" << "\n";
        else {
            sz++;
            if(front == -1)front = 0;
            rear = (rear + 1) % Mx;
            arr[rear] = value;
            cout << value << " Pushed" << "\n";
        }
    }
    void pop() {
        int element;
        if(empty())cout << "Underflow" << "\n";
        else {
            sz--;
            element = arr[rear];
            if(front == rear) front = rear = -1;
            else front = (front + 1) % Mx;
            cout << element << " Popped" << "\n";
        }
    }
    void display() {
        if(empty()) {
            cout << "Empty" << "\n";
        }else {
            for(int i = front; i != rear; i = (i + 1) % Mx)
                cout << arr[i] << " ";
            cout << arr[rear] << "\n";
        }
    }
};
int main() {
    CircularQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
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
