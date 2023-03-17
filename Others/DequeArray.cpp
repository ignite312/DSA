#include<bits/stdc++.h>
using namespace std;
const int Mx = 3;

class CircularQueue {
    int arr[Mx], front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool empty() {
        return front == -1;
    }
    bool full() {
        return ((front == 0 && rear == Mx - 1) || front == rear + 1);
    }
    int size() {
        return (rear - front + Mx) % Mx + 1;
    }
    void push_front(int value) {
        if(full())cout << "Overflow" << "\n";
        else {
            if(front == -1)front = rear = 0;
            else front = (front - 1 + Mx) % Mx;
            arr[front] = value;
            cout << value << " Pushed in front" << "\n";
        }
    }
    void push_back(int value) {
        if(full())cout << "Overflow" << "\n";
        else {
            if(front == -1)front = rear = 0;
            else rear = (rear + 1) % Mx;
            arr[rear] = value;
            cout << value << " Pushed in back" << "\n";
        }
    }
    void pop_front() {
        if(empty())cout << "Underflow" << "\n";
        else if(front == rear)front = rear = -1;
        else front = (front + 1) % Mx;
    }
    void pop_back() {
        if(empty())cout << "Underflow" << "\n";
        else if(front == rear)front = rear = -1;
        else rear = (rear - 1 + Mx) % Mx;
    }
    int get_front() {
        if(empty())cout << "Empty" << "\n";
        else return arr[front];
    }
    int get_back() {
        if(empty())cout << "Empty" << "\n";
        else return arr[rear];
    }
    void display() {
        if(empty())cout << "Empty" << "\n";
        else {
            for(int i = front; i != rear; i = (i + 1) % Mx)
                cout << arr[i] << " ";
            cout << arr[rear] << "\n";
        }
    }
};
int main() {
    CircularQueue q;
    q.push_back(1);
    q.push_front(2);
    q.push_back(3);
    q.push_front(3);
    q.display();
    cout << "Total Size: " << q.size() << "\n";
    cout << q.empty() << "\n";
    q.pop_back();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    cout << q.empty() << "\n";
    cout << "Total Size: " << q.size() << "\n";
}
