// https://cses.fi/problemset/task/1145
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
const int MAX_N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int maxs = 1;
    for (int i = 0; i < n; i++) {
        maxs = max(dp[i], maxs);
    }
    cout << maxs;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
