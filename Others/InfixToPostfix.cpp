#include <bits/stdc++.h>
using namespace std;

int priority (char alpha){
    if(alpha == '+' || alpha =='-') return 1;
    if(alpha == '*' || alpha =='/') return 2;
    if(alpha == '^') return 3;
    return 0;
}
string convert(string infix) {
    int i = 0;
    string postfix = "";
    stack <int> st;
    while(infix[i] != '\0') {
        if(infix[i] >= '0' && infix[i] <= '9'|| infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= 'a'&& infix[i] <= 'z'){
            postfix += infix[i];
        }else if(infix[i]=='('){
            st.push(infix[i]);
        }else if(infix[i]==')') {
            while(st.top()!='('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }else {
            while(!st.empty() && priority(infix[i]) <= priority(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        i++;
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix = "3+4*2/(1-5)^2^3"; 
    string postfix;
    postfix = convert(infix);
    cout << "Postfix is : " << postfix;
    return 0;
}
