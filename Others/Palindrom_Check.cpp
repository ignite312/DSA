#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& str) {
    stack<char> st;
    queue<char> q;
    for (char c : str) {st.push(c), q.push(c);}
    while (!st.empty() && !q.empty()) {
        if (st.top() != q.front())return false;
        st.pop(),q.pop();
    }
    return true;
}
int main() {
    string s = "abcgcba";
    if(isPalindrome(s))cout << "The string is a palindrome.\n";
    else cout << "The string is not a palindrome.\n";
    return 0;
}
