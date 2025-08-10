// https://cses.fi/problemset/task/1746
// combinatorics
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
const int INF = 1e9;

// dp[idx][prev]
int dp[MAXN][107];

int main() {
    int n, m;
    cin >> n >> m;

    int x[n + 7];
    for (int i = 1; i <= n; i++) cin >> x[i];

    if (x[1] == 0) {
        for (int i = 1; i <= m; i++) dp[1][i] = 1;
    } else {
        dp[1][x[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int diff = -1; diff <= 1; diff++) {
                if (1 <= j && j <= m) {
                    dp[i][j] += dp[i - 1][j + diff];
                    dp[i][j] %= MOD;
                }
            }
        }
        if (x[i] != 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n][j];
        ans %= MOD;
    }
    cout << ans << endl;
}
