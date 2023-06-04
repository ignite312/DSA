#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
    map<char, int> check = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
    stack<char> st;
    for(int i = 0; i < (int)s.size(); i++) {
        if(check[s[i]] < 0)st.push(s[i]);
        else {
            if(st.empty())return false;
            if(check[st.top()] + check[s[i]] != 0)return false;
            st.pop();
        }
    }
    if(st.empty())return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        cout << (is_valid(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}
