#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    if (getline(cin >> ws, s)) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}