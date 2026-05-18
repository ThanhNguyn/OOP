#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int start = 0;
    int max_len = 0;

    auto expand_around_center = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; 
    };

    for (int i = 0; i < s.length(); i++) {
        int len1 = expand_around_center(i, i);     
        int len2 = expand_around_center(i, i + 1); 
        
        int current_max = max(len1, len2);
        
        if (current_max > max_len) {
            max_len = current_max;
            start = i - (current_max - 1) / 2;
        }
    }

    cout << s.substr(start, max_len) << "\n";
    return 0;
}