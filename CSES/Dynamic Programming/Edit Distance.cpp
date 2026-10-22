// https://cses.fi/problemset/task/1639
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
const int MAX_N = 5005;

int dp[MAX_N][MAX_N];

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    for (int i = 0; i <= n; i++) dp[i][0] = i; // delete all i char
    for (int j = 0; j <= m; j++) dp[0][j] = j; // insert all j char

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j - 1], // replace
                                   dp[i - 1][j],     // insert
                                   dp[i][j - 1]      // delete
                               });
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
