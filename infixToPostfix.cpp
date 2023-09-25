#include<iostream>
#include<stack>
using namespace std;
int prec(char op) {
    switch (op) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    case '(': return 0;
    }
    return -1;
}
string infixToPostfix(string exp) {
    stack<char> st;
    string ans = "";
    for (char i : exp) {
        if ((i >= 'a' && i <= 'z') || (i >= 48 && i <= 57)) {
            ans += i;
        }
        else {
            if (st.empty()) {
                st.push(i);
            }
            else if (i == ')') {
                while (st.top() != '(') {
                    char temp = st.top();
                    ans += temp;
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && (prec(i) < prec(st.top()))) {
                    char temp = st.top();
                    ans += temp;
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << infixToPostfix(s);
}