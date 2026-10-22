#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1'000'000'007;
const int MAXN = 100'005;
const int MAXM = 105;

// index i has value j
int dp[MAXN][MAXM];

signed main() {
    int n, m;
    cin >> n >> m;
    int x[n + 1];
    for (int i = 1; i <= n; i++) cin >> x[i];

    if (x[1] == 0) {
        for (int j = 1; j <= m; j++) dp[1][j] = 1;
    } else {
        dp[1][x[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int diff = -1; diff <= 1; diff++) {
                    int prev = j + diff;
                    if (1 <= prev && prev <= m) {
                        dp[i][j] += (dp[i - 1][prev]) % MOD;
                    }
                }
            }
        } else {
            for (int diff = -1; diff <= 1; diff++) {
                int prev = x[i] + diff;
                if (1 <= prev && prev <= m) {
                    dp[i][x[i]] += (dp[i - 1][prev]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans << endl;
}
