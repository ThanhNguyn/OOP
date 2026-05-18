#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!getline(cin, s)) return 0;

    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "NO\n";
                return 0;
            }
            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                st.pop();
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (st.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}