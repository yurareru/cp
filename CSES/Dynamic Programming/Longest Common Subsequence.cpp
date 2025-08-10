// https://cses.fi/problemset/task/3403/
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
const int MAX_N = 1005;

int dp[MAX_N][MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    int a[MAX_N];
    int b[MAX_N];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << nl;
    vector<int> lcs;
    while (n > 0 && m > 0) {
        if (a[n - 1] == b[m - 1]) {
            lcs.pb(a[n - 1]);
            n--;
            m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) {
            n--;
        } else {
            m--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for (auto x : lcs) cout << x << " ";
    cout << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
