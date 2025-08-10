// https://cses.fi/problemset/task/2413
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define berak break
#define Bismillah ios_base::sync_with_stdio(0);
#define AC cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 1e6 + 5;

ll add(ll a, ll b) { return (a + b) % MOD; }

ll dp[MAX_N][3];

void solve() {
    int n;
    cin >> n;
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        // menyatu/tidak + i-1 = 2 balok
        dp[i][1] = add(2 * dp[i - 1][1], dp[i - 1][2]);

        // i-1 = 1 balok + 4 * i-1 = 2 balok (menyatu/tidak)
        dp[i][2] = add(dp[i - 1][1], 4 * dp[i - 1][2]);
    }
    cout << add(dp[n][1], dp[n][2]) << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
