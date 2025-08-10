// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
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
    ll total = 1LL * n * (n + 1) / 2;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << total - sum << nl;
}

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
