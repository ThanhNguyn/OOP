#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<long long, int> pos;
    for (int j = 0; j < n; ++j) {
        long long need = t - a[j];
        auto it = pos.find(need);
        if (it != pos.end()) {
            cout << it->second << " " << j;
            return 0;
        }
        pos[a[j]] = j;
    }
    return 0;
}
