#include<bits/stdc++.h>
using namespace std;
const int MX = 3;

class Stack {
    int peek;
public:
    int st[MX];
    Stack() {
        peek = -1;
    }
    bool empty();
    void push(int x);
    void pop();
    void top();
    int size();

};
bool Stack::empty() {
    return (peek == -1);
}
int Stack::size() {
    return peek+1;
}
void Stack::push(int x) {
    if(peek >= MX - 1) {
        cout << "Stack Overflow\n";
        return;
    }else {
        st[++peek] = x;
        cout << x << " Pushed into Stack\n";
    }
}
void Stack::pop() {
    if(peek == -1) {
        cout << "Stack Underflow\n";
        return;
    }else {
        int x = st[peek--];
        cout << x << " Popped from Stack\n";
    }
}
void Stack::top() {
    if(peek == -1) {
        cout << "Stack is Empty\n";
        return;
    }else {
        int x = st[peek];
        cout << "Top element is: " << x << "\n";
    }
}
int main() {
    class Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "The size of te Stact is: " << st.size() << '\n';
    st.top();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.top();
    cout << (st.empty() ? "Stack is Empty\n" : "Stack isn't Empty\n");
}
