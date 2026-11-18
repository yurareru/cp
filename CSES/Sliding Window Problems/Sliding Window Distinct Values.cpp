// https://cses.fi/problemset/task/3222/
// sliding window
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

void solve() {
    int n, k;
    cin >> n >> k;

    vi v(n);

    for (auto& i : v) cin >> i;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[v[i]]++;
        if (i >= k) {
            m[v[i - k]]--;
            if (m[v[i - k]] == 0) m.erase(v[i - k]);
        }
        if (i >= k - 1) cout << m.size() << " ";
    }
    cout << nl;
}
