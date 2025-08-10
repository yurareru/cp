// https://tlx.toki.id/problems/ksnp-2021/B3
#include <bits/stdc++.h>

using namespace std;

int dp[2][100'005];
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1), k(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i] >> k[i] >> d[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = i & 1, prv = (i - 1) & 1;
        for (int j = 0; j <= m; j++) {
            dp[cur][j] = dp[prv][j]; // skip
            if (j < h[i]) continue;
            if (d[i]) {
                dp[cur][j] = max({
                    dp[cur][j],
                    dp[prv][j - h[i]] + k[i] // take and go next
                });
            } else {
                dp[cur][j] = max({
                    dp[cur][j],
                    dp[cur][j - h[i]] + k[i], // take again
                });
            }
        }
    }
    cout << dp[n & 1][m] << endl;
}
