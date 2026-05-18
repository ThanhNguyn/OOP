#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    if (!(cin >> k >> n)) return 0;

    vector<int> coins(k);
    for (int i = 0; i < k; ++i) {
        cin >> coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int c : coins) {
            if (i >= c && dp[i - c] != INF) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[n] << "\n";
    }

    return 0;
}