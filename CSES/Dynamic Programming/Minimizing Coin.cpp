// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e9;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        cin >> cs[i];
    }
    vector<int> dp(x + 1, LIM);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int c : cs) {
            if (i - c >= 0 && dp[i - c] != LIM) {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }
    if (dp[x] == LIM) {
        cout << -1;
    } else {
        cout << dp[x];
    }
}
