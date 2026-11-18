#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);

constexpr char nl = '\n';
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr int MAX_N = 1005;

void solve();

int main() {
    Bismillah AC;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

bool getbit(int x, int pos) { return (x >> pos) & 1; }

void solve() {
    int n, m, k, l, r, x;
    cin >> n >> m >> k >> l >> r >> x;

    vi a(n);
    vector<pii> conflict;
    vector<pii> prequisite;

    for (auto& i : a) cin >> i;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        conflict.pb({u, v});
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        prequisite.pb({u, v});
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int total = 0;
        int amin = INF, amax = -INF;
        for (int i = 0; i < n; i++) {
            if (getbit(mask, i)) {
                total += a[i];
                amin = min(amin, a[i]);
                amax = max(amax, a[i]);
            }
        }
        if (l <= total && total <= r && abs(amax - amin) == x) ans++;
    }
    cout << ans << nl;
}
