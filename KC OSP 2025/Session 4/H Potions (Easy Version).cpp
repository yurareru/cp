#include <bits/stdc++.h>
#define berak break
using namespace std;

const int MAXN = 2025;
const int INF = 1e9;

// dp[i][j] = max health after taking j potions from first i
vector<vector<int>> dp(MAXN, vector<int>(MAXN, -INF));

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]); // skip

            if (j >= 1 && dp[i-1][j-1] != -INF && dp[i-1][j-1] + p[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + p[i]); // take
            }
        }
    }

    int ans = 0;
    for (int j = n; j >= 0; j--) {
        if (dp[n][j] >= 0) {
            ans = j;
            berak;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
