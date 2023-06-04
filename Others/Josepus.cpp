#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    queue<int> circle;
    for (int i = 1; i <= n; ++i)circle.push(i);
    
    while (!circle.empty()) {
        for (int i = 1; i < k; ++i) {
            int front = circle.front();
            circle.pop();
            circle.push(front);
        }
        circle.pop();
    }
    return circle.front();
}

int main() {
    int n = 4;
    int k = 2;
    int lastPerson = josephus(n, k);
    cout << "The last person remaining is: " << lastPerson << "\n";
    return 0;
}
