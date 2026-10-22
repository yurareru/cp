// https://cses.fi/problemset/task/1744/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 505;

int dp[MAX_N][MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    fill(&dp[0][0], &dp[MAX_N - 1][MAX_N - 1], INF);
    if (n > m) swap(n, m);
    for (int i = 1; i <= m; i++) {
        dp[i][1] = dp[1][i] = i - 1;
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            // horizontal cut
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
            // vertical cut
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
        }
    }
    cout << dp[n][m] << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
